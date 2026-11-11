#include<bits/stdc++.h>
using namespace std;

int a[1000010];
int vis[500010];
int t[500010],t2[500010];

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]]++;
		t2[a[i]]++;
	}
	int id=0
	for(int i=n;i>=1;i--){
		int x=a[i];
		if(vis[x][0]==0){
			id++;
			vis[id][0]=x;
			vis[id][1]=i;
		}
		if(id==m)break;
	}
	int cnt=vis[id][1];
	for(int i=cnt+1;i<=n;i++){
		int x=a[i];
		if(i!=vis[x][1]){
			i++;
			while(i<vis[x][1]){
				int y=a[i];
				vis[y][2]=10;
				i++;
			}
		}
	}
	for(int i=id-1;i>=1;i--){
		int x=vis[i][0];
		int y=vis[i+1][0];
		t2[x]+=t2[y];
	}
	for(int i=1;i<=m;i++){
		if(vis[i][2]==0){
			cout<<t2[i]<<" ";
		}else{
			cout<<t[i]<<" "; 
		}
	}
	return 0;
}
