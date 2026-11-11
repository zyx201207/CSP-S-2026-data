//#include<c++bits/std.h>
#include<iostream>
using namespace std;
int a1,a2,n,i=1,m,ans=0,b[100000],h=0,v[100000],vis[100000]={0},maxx=0;
string c1,s1,c2,s2;
char s;
void dfs(int pos){
	if(pos==m+1){
		int h=524287;
		for(int i=1;i<=m;i++){
			h=(h&b[v[i]]);	
		}maxx=max(h,maxx);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1)continue;
		if(i<v[pos-1] and pos!=1)continue;
		v[pos]=i;
		vis[i]=1;
		dfs(pos+1);
		vis[i]=0;
	}
}
int main(){
	cin>>n>>m;
//	for(int i=1;i<=n;i++){
//		cin>>a1;
//		a2=a1;
//		int j=0;
//		while(a2>0){
//			b[i][j]=a2%2;
//			a2/=2;
//			j++;		
//		}
//		h=max(h,j);
//	}for(int i=1;i<=n;i++){
//		for(int k=0;k<h;k++){
//			cout<<b[i][k]<<" "; 
//		}cout<<endl;
//	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	dfs(1);
	cout<<maxx;
	return 0;
} 
