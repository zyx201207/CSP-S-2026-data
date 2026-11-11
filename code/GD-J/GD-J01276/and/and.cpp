#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
long long a[200002],awy=0;
bool vis[200002];
void dfs(int id,long long anweiyu){
	if(id>m){
		if(awy<anweiyu){
			awy=anweiyu;
		}
		return ;
	}
	if(id==1){
		for(int i=0;i<n;i++){
		    if(vis[i]==0){
			    vis[i]=1;
			    dfs(id+1,a[i]);
			    vis[i]=0;
		    }
	    }
	}
	for(int i=0;i<n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(id+1,anweiyu&a[i]);
			vis[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		vis[i]=0;
	}
	dfs(1,0);
	cout<<awy;
	return 0;
}
