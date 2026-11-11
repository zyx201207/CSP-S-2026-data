#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,maxx,t,ans;
ll a[200010];
bool f[200010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); 
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	t=m;
	if(m==1){
		cout<<maxx;
		return 0;
	}
	if(m==2){
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				ans=max(ans,i&j);
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
