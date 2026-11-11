#include<bits/stdc++.h>
using namespace std;
struct node{
	int aa,tt;
};
int c,n,m,d,q,w[500005],k[500005],a[505][25],t[505][25],_min,s,e;
bool vis[500005];
vector<node> v[500005];
void dfs(int x,int y){
	cout<<"a";
	if(x==e){
		_min=min(_min,y);
		return;
	}
	vis[x]=1;
	for(int i=1;i<=v[x].size();i++){
		for(int j=1;j<=k[v[x][i].aa];j++){
			if(vis[a[v[x][i].aa][j]]==0){
				vis[a[v[x][i].aa][j]]=1;
				dfs(a[v[x][i].aa][j],y+v[x][i].tt+t[v[x][i].aa][j]);
				vis[a[v[x][i].aa][j]]=0;
			}	
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			node temp;
			cin>>a[i][j]>>t[i][j];
			temp.aa=i;
			temp.tt=t[i][j];
			v[a[i][j]].push_back(temp);
		}
	}
	for(int i=1;i<=q;i++){
		_min=0x3f3f3f3f;
		cin>>s>>e;
		dfs(s,w[s]+w[e]);
		cout<<_min<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
