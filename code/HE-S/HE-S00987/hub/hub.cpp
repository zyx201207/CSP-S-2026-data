#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,f[5005][5005],in[5005],pe[5005],ans;
long long dist[5005][5005];
void tree(int u,int fa){
	if(pe[u]==fa){
		if(fa-4>0) cout<<fa-4<<'\n';
		else cout<<fa<<'\n';
		return ;
	}
	if(pe[u]-8>0){
		cout<<pe[u]-8<<'\n';
	}
	else cout<<pe[u]<<'\n';
	return ;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		ans=0;
		for(int i=1;i<=n;i++){
			in[i]=0;
			for(int j=1;j<=n;j++){
				f[i][j]=1;
				f[j][i]=1;
				pe[j]=i;
				dist[i][j]=0;
			}
		}
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			f[u][v]=1;
			in[u]++;
		}
		for(int i=1;i<=n;i++) if(in[i]==0){tree(i,0);break;}
	}
	return 0;
}
