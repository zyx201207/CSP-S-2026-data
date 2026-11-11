#include<bits/stdc++.h>
#define re register
using namespace std;
typedef long long ll;
int n;
ll m;
ll a[500100];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(re int i=1;i<=n;i++)scanf("%lld",&a[i]);
        sort(a+1,a+1+n);
	if(n<=5000){
		int maxx=0;
		for(re int i=1;i<=n;i++){
			ll sum=0;
			int cnt=0;
			for(re int j=i;j>=1;j--){
				sum+=abs(a[i]-a[j]);
				if(sum<=m)cnt++;
				else if(sum>m)break;
			}
			maxx=max(maxx,cnt);
		}
		printf("%d",maxx);
		return 0;
	}
	bool flag=0;
	for(re int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
			flag=1;
			break;
		}
	}
	if(flag==0){
		printf("%lld",m/(a[2]-a[1]));
		return 0;
	}
	else {
		ll sum=0;
		int cnt=0;
		int k;
		for(re int i=1;i<=n;i++){
			sum+=a[i+1]-a[i];
			if(sum>=m){
				k=i;
				break;
			}
		}
		sum=0;
		for(re int i=k;i>=1;i--){
			sum+=abs(a[k]-a[i]);
			if(sum>m)break;
			cnt++;
		}
		printf("%d",cnt);
		return 0;
	}
	return 0;
}
