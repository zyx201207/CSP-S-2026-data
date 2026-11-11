#include<bits/stdc++.h>
using namespace std;
int n,d,qd,zd,s,zh,db;
bool f[505][505]={0};
int z[5005]={0};
void dfs(int x){
	for(int i=x+1;i<=n;i++){
		if(z[i]-z[x]<=d){
			 f[x][i]=1;
			 dfs(i);
		}
	}
}
void dfs2(int x,int bs){
	if(x>zd){
		return ;
	}
	if(x==zd){
		if(bs<db){
			db=bs;
			zh=1;
		}else if(bs==db){
			zh++;
		}
		return ;
	}
	for(int i=x+1;i<=n;i++){
		if(f[x][i]==1){
			 dfs2(i,bs+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;
	cin>>t>>t;
	while(t--){
		s=0;
		memset(f,0,sizeof(f));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>z[i];
		}
		dfs(1);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(f[i][j]==0){
					qd=i;
					zd=j;
					zh=0;
					db=505;
					dfs2(qd,0);
					if(zh==2){
						s++;
					}
				}	
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
