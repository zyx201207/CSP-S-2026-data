#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int N=5e2+7;
int c,n,m,d,q,x,y;
ll w[N];
int vis[N];
ll ans;
struct li{
	int k;
	int a[N];
	int t[N];
}tot[5007];
void dfs(int h,ll t){
	if(vis[h])	return;
	vis[h]=1;
	if(h==y){
		ans=min(ans,t);
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=tot[i].k;j++){
			if(tot[i].a[j]==h){
				for(int k=1;k<=tot[i].k;k++){
					if(k==h) continue;
					dfs(tot[i].a[k],t+tot[i].t[k]+tot[i].a[h]);
				}
			}
		}
	}
	vis[h]=0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>tot[i].k;
		for(int j=1;j<=tot[i].k;j++){
			cin>>tot[i].a[j]>>tot[i].t[j];
		}
	}
	while(q--){
		cin>>x>>y;
		ans=114524233;
		dfs(x,w[x]);
		cout<<ans+w[y]<<endl;
	}
	return 0;
}

