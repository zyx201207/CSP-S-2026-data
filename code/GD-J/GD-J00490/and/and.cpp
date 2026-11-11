#include <bits/stdc++.h>
using namespace std;
long long a[200000]={};
long long s=-1;
int n,m;//总共n个数，选m个数 
void dfs(int g,int w,long long z){
	if(g==m){
		s=max(s,z);
		return;
	}
	if(w>n-1){
		return;
	}
	dfs(g+1,w+1,(z&a[w]));
	dfs(g,w+1,z);
//	cout<<g;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(0,0,pow(2,31)-1);
	cout<<s;
	return 0;
}
