#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN=5e5+5;
int n;ll m;

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	vector<ll> a;
	scanf("%d%lld",&n,&m);
	a.resize(n);
	for(int i=0;i<n;i++) {
		scanf("%lld",&a[i]);
	}
	sort(a.begin(),a.end());
	ll tot=m;
	
	for(int i=0;i<n&&tot;i++) {
		// 将a[0]~a[i]同加到a[i+1]
		ll sum=0;
		//printf("%d\n",i);
		for(int j=0;j<=i;j++) {
			sum+=a[i+1]-a[j];
		}
		//printf("%lld %lld\n",sum,tot);
		if(sum<=tot) {
			//printf("A\n");
			for(int j=0;j<=i;j++) {
				a[j]=a[i+1];
			}
			tot-=sum;
		} else {
			//printf("B\n");
			for(int j=i;sum>0&&j>=0;j++) {
				if(sum>=a[i+1]-a[j]) {
					sum-=(a[i+1]-a[j]);
					a[j]=a[i+1];
				} else {
					a[j]+=sum;
					sum=0;
				}
			}
			tot=0;
		}
//		for(int i=0;i<n;i++) {
//			printf(" %d",a[i]);
//		}printf("\n");
	}
	vector<pair<ll,int>> vec;
	for(int i=0;i<n;i++) {
		int cnt=1;
		for(;i&&i<n;i++) {
			if(a[i]!=a[i-1]) break;
			cnt++;
		}
		vec.push_back(pair<ll,int>(a[i],cnt));
	}
	sort(vec.begin(),vec.end(),[](pair<ll,int> u,pair<ll,int> v){
		return u.second>v.second;
	});
//	for(auto i:vec) {
//		printf("%d %d\n",i.first,i.second);
//	}
	printf("%d",vec[0].second);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

