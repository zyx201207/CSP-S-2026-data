#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+7;
ll m,a[N],l,r,x,f=1,mi=1e18,ma=-1e18;
int n;
bool cmp(ll y,ll z){
	return y-x<z-x;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
		mi=min(mi,a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++) if(a[i]-a[i-1]!=a[2]-a[1]) f=0;
	if(f){
		ll l=n,c=a[n];
		while(l>=1&&m){
			int f=0;
			if(m>=c-a[l]&&l>=1){
				f=1;
				m-=(c-a[l]);
				l--;
			}
			if(!f) m=0;
		}
		l++;
		cout<<n-l+1;
	}
	else if(n>5000){
		ll ans=0;
		for(x=mi;x<=ma;x++){
			ll c=m,sum=0;
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n;i++){
				if(a[i]>x) continue;
				else if(c>=x-a[i]){
					sum++;
					c-=(x-a[i]);
				}
				else break;
			}
			ans=max(ans,sum);
		}
		cout<<ans;
	}
	else{
		ll ans=0;
		for(int j=1;j<=n;j++){
			x=a[j];
			ll c=m,sum=0;
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n;i++){
				if(a[i]>x) continue;
				else if(c>=x-a[i]){
					sum++;
					c-=(x-a[i]);
				}
				else break;
			}
			ans=max(ans,sum);
		}
		cout<<ans;
	}
	return 0;
}
