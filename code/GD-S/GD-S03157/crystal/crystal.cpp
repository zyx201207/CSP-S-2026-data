#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6;
ll n,m;
ll a[N],minu[N],sump[N],summ[N],sums[N];
bool r(ll a,ll b){
	return a<b;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1,r);
	for(int i=1;i<=n;i++){
		minu[i]=a[i]-a[i-1];
		sump[i]=sump[i-1]+a[i];
		if(i!=1)summ[i]=summ[i-1]+minu[i];
		if(i!=1)sums[i]=sums[i-1]+(i-1)*minu[i];
//		cout<<a[i]<<" "<<minu[i]<<" "<<summ[i]<<" "<<sums[i]<<"\n";
	}
	long long ans=0;
	int l=1,r=2,sta=2;
	for(l,r;r<=n;l=1,r=++sta){
		int lastr=r,lastl;
		while(l!=r&&l!=lastl&l!=lastr){
			int midl=(l+lastl)/2;
			int midr=(l+lastr)/2;
			if(m>=sums[r]+sump[l-1]-(l-1)*a[r]){
				lastr=l;
				ans=max(ans,(ll)r-l+1);
				l=midl;
			}
			else{
				lastl=l;
				l=midr;
			}
		}
	}
	cout<<ans;
	return 0;
}
