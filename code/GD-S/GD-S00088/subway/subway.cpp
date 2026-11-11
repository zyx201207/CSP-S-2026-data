#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=510;
int C,n,m,D,q;
int w[N];
int k[N],a[N],t[N];
int d[1010][1010];
int fa[N];
vector<int> a2[M];
unordered_map<int,bool> mp[M];
vector<int> e[M];
signed main(){
	freopen("subway.in","r",stdin); 
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>D>>q;
	if(C<=11){
		memset(d,0x3f,sizeof d);
		for(int i=1;i<=m;i++)
			cin>>w[i];
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				cin>>a[j];
				cin>>t[a[j]];
			}
			for(int j=1;j<=k[i];j++)
				for(int l=1;l<=k[i];l++)
					d[a[j]][a[l]]=d[a[l]][a[j]]=t[a[j]]+t[a[l]];
		}
		for(int l=1;l<=m;l++)
			for(int i=1;i<=m;i++)
				for(int j=1;j<=m;j++)
					d[i][j]=d[j][i]=min(d[i][j],d[i][l]+d[l][j]);
		while(q--){
			int x,y;
			cin>>x>>y;
			cout<<d[x][y]+w[x]+w[y]<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
