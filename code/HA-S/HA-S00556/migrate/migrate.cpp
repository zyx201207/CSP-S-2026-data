#include <bits/stdc++.h>
using namespace std;

int c,t;
int n,d;
int num;
int x[2000001]={};
int lennum[2000001]={};

void dfs(int i,int v,int l){
	if (i==v){
		lennum[l]++;
		return ;
	}
	for (int o=i+1;x[o]-x[i]<=d;o++){
		if (o<=v) dfs(o,v,l+1);
	}
}

int ishort(int u,int v){
	memset(lennum,0,sizeof lennum);
	dfs(u,v,0);
	for (int i=1;i<=v-u;i++){
		if (lennum[i]!=0){
			return lennum[i];
		} 
	}
	return 0;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while (t--){
		memset(x,0,sizeof x);
		cin>>n>>d;
		num=0;
		for (int i=1;i<=n;i++){
			cin>>x[i];
		}
		for (int u=1;u<=n-2;u++){
			for (int v=u+2;v<=n;v++){
				if (ishort(u,v)==2){
					num++;
				}
			}
		}
		cout<<num<<"\n";
	}
	return 0;
}
