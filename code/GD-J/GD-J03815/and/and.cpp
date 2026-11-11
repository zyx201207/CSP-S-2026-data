#include<iostream>
using namespace std;
int list[10000000];
int vis[10000000];
int n,m,maxn;
void dfs(int num,int ts){
	if(ts==m){
		maxn=max(maxn,num);
		return;
	}
	for(int i=0;i<n;i++){
		if(vis[i]!=1){
			vis[i]=1;
			if(ts!=0)dfs(num&list[i],ts+1);
			else dfs(i,ts+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>list[i];
	}
	dfs(0,0);
	cout<<maxn;
}
