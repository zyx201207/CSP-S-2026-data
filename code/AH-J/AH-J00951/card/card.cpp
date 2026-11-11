#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[1000000],pos[300005],f[1000000],dis[300005];
bool vis[300005];
void part(){
	for(ll ti=1;ti<=n;ti++){
		memset(vis,0,sizeof vis);
		memset(f,0,sizeof f);
		memset(pos,0,sizeof pos);
		ll last=0;
		for(ll i=ti;i<=n;i++){//i-下标 a[i]-数字
			if(pos[a[i]]==0){
				pos[a[i]]=++last;
				vis[a[i]]=1;
				f[last]=a[i];
			}
			else{
				for(ll j=pos[a[i]]+1;j<=last;j++){//f[j]-位置J上的数字
					vis[f[j]]=0;
					f[j]=0;
					pos[f[j]]=0;
				}
				last=pos[a[i]];
			}
		}
		for(ll j=1;j<=m;j++){
			if(vis[j]==1){
				dis[j]++;
			}
		}
	}
	for(ll i=1;i<=m;i++){
		printf("%lld ",dis[i]);
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	part();
	return 0;
}

