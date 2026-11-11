//GZ-S00334 华东师范大学附属贵阳学校 向耕立
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX_N=1e6+10;
ll c,d,n,m,a[MAX_N],cnt=0;
void dfs(ll x,ll y,ll now,ll gl){
	// cout<<x<<' '<<y<<' '<<cnt<<' '<<now<<' '<<gl<<endl;
	if(cnt>2)return;
	if(x>n||x>y)return;
	if(x==y){
		if(now==gl)cnt++;
		return;
	}
	for(ll i=x+1;a[x]+m>=a[i]&&i<=n&&cnt<=2;i++){
		dfs(i,y,now+1,gl);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>d;
	while(d--){
		cin>>n>>m;
		for(ll i=1;i<=n;i++){cin>>a[i];}
		ll ans=0;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1,dis=0;j<=n;j++){
				dis=0;
				for(ll k=i,lt=i;k<=j;k++){
					if(a[lt]+m<=a[k]){dis++;lt=k;/*cout<<lt<<' '<<a[lt]<<' '<<k<<' '<<a[k]<<'-'<<dis<<endl;*/}
				}
				dis++;
				cnt=0;
				dfs(i,j,0,dis);
				if(cnt==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}