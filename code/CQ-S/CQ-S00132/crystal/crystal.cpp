#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	ll ans=0;
	for(int j=1;j<=n;j++){
		ll cnt=0,f=-1e15,fg=-1e15,l=1,x=m;
		for(int i=j;i<n;i++){
			if(l){
				if(a[i]<a[i+1]){
					if(x>=(i+1-j)*(a[i+1]-a[i])){
						x-=(i+1-j)*(a[i+1]-a[i]);
					}
					else{
						cnt+=(x/(a[i+1]-a[i]));
						f=a[i+1];
						fg=i+1-j;
						l=0;
					}
				} 
			}
			else{
				if(a[i]==f)cnt++;
			}
		}
		ans=max({ans,cnt,fg});
	}
	cout<<ans;
	return 0;
}                     
