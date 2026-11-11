#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,minn=1e9,w[505],k[505],s[500005],f[505][100005],a[100005];
void dfs(int now,int end,int ans){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j==end && f[i][j]!=0 && f[i][now]!=0){
				minn=min(minn,ans+f[i][now]+f[i][j]);
				return ;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[j]>1 && s[j]==0 && f[i][now]!=0 && f[i][j]!=0){
				s[j]=1;
				dfs(j,end,ans+f[i][now]+f[i][j]);
				s[j]=0;
			}
		}
	}
}

int main(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i]; 
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			f[i][x]=y;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(f[i][j]!=0) a[j]++; 
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		s[x]=1;
		dfs(x,y,w[x]+w[y]);
		cout<<minn<<endl;
		memset(s,0,sizeof(s));
		minn=1e9;
	}
	return 0;
}
