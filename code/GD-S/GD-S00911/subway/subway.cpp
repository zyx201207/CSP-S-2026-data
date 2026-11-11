#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500005],k[505],x,y;
int ll[500005],s[500005];
vector<int>lk[505];
unordered_map<int,unordered_map<int,int>>l,a,t,ztx;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			ztx[i][a[i][j]]=j;
			lk[a[i][j]].push_back(i);
		}
	}
	while(q--){
		memset(s,127,sizeof s);
		memset(ll,0,sizeof ll);
		cin>>x>>y;
		if(l[x][y]){
			cout<<l[x][y]+w[x]+w[y]<<'\n';
			continue;
		}
		queue<int>qq;s[x]=0;
		for(int i:lk[x])qq.push(x);
		while(qq.size()){
			int u=qq.front();qq.pop();
			for(int i:lk[u]){
				for(int j=1;j<=k[i];j++){
					int id=a[i][j];
					if(ll[id])continue;
					qq.push(id);ll[u]=1;
					s[id]=min(s[id],s[u]+t[i][ztx[i][u]]+t[i][j]);
				}
			}
		}
		for(int i=1;i<=m;i++)if(i!=x)l[x][i]=l[i][x]=s[i];
		cout<<l[x][y]+w[x]+w[y]<<'\n'; 
	} 
}
