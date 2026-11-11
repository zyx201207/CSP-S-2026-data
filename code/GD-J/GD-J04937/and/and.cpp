#include<bits/stdc++.h>
using namespace std;
bool vis[10000];
int sz[10000];
int xl(int n,int m){
	int a=0;
	if(m==2){
		return 0;
	}else{
	for(int i=0;i<n;i++){
		if(vis[i]==1)continue;
		vis[i]=1;
		
		vis[i]=0;
	}
	return a;
}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>sz[i];
	}
	cout<<xl(n,m);
	return 0;
} 
