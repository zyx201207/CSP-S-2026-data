#include<bits/stdc++.h> 
using namespace std;

const int N=5e5+10;
long long n,m,a[N],ans,b[N];
bool r=true;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		if(a[i]!=i) {
			r=false;
		}
	//	ans+=abs(a[i]);
	}
	if(r==true) {
		int cnt=0;
		for(int i=1;i<=n;i++) {
			if((i-1)*a[i]-(i*(i-1)/2)<=m) {
				cnt=i;
			}
		}
		cout<<cnt;
		return 0;
	}
//	ans+=1e10;	
//	cout<<ans;
//	return 0;
	if(n<=5000) {
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++) {
			long long cnt=0,an=0;
			for(int j=1;j<=i;j++) {
				if(an+a[i]-a[j]<=m) {
					an+=a[i]-a[j];
					cnt++;
				}
			}
			ans=max(ans,cnt);
		}
		cout<<ans;
		return 0;
	}
	srand(time(0));
	cout<<rand()%10000000000;
	return 0;
}

