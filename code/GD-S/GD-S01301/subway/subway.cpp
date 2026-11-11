#include<bits/stdc++.h>
#include<queue>
#define INF (1<<31-1)
using namespace std;
int n,m,d,p,k[505],a[505][500005],t[505][500005],z,y,s[500005],minn;
bool bl[500005];
queue<int> q[500005];
void dfs(int x,int minxx){
	if(x==z)
		minn=min(minn,minxx);
	for(int i=1;i<=k[x];i++){
		if(bl[a[x][i]]==0){
			bl[a[x][i]]=1;
			minxx+=t[x][i];
			dfs(a[x][i],minxx);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)
		cin>>s[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}	
	}
	for(int h=1;h<=p;h++){
		cin>>z>>y;
		memset(bl,0,sizeof(bl));
		minn=INF;
		int as=s[z];
		dfs(z,as);
	}
	return 0;
}
