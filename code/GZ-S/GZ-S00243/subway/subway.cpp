//贵阳市第三实验中学 梁佑琳 GZ-S00243 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,m,d,q;
ll k[600],a[600][600],t[600][600],w[600];
bool flag=false;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		ll x,y;
		cin>>x>>y;
		ll b=0,ans=0;
		for(ll i=1;i<=n;i++){
			ll cnt=0;
			for(ll j=1;j<=k[i];j++){
				if(x==a[i][j]||y==a[i][j]){cnt++;}
			}
			if(cnt==2){flag=true;b=i;}
		}
		if(flag==true){
			ans=w[x]+t[b][x]+t[b][y]+w[y];
			cout<<ans<<endl;
		}
		if(flag==false){
			ans=w[x]+w[y];
			for(ll i=1;i<=n;i++){
				for(ll j=1;j<=k[i];j++){
					if(a[i][j]==x){
						ans+=t[i][j];
					}
					if(a[i][j]==x+1){
						ans+=t[i][j];
					}
					if(a[i][j]==y){
						ans+=t[i][j];
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
