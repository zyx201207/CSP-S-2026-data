#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,maxx=-999;
long long a[N];
void dfs(int b,int id,int c){
//	cout<<b<<" "<<id<<" "<<c<<endl;
	if(c==m){
		maxx=max(maxx,b);
		return ;
	}
	for(int i=id;i<=n-m+c+1;i++){
		long long l=b&(a[i]);
		dfs(l,i+1,c+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i]; 
	for(int i=1;i<=n-m+1;i++){
		dfs(a[i],i+1,1);			
	}
	cout<<maxx;
	return 0;
}
//都是同龄人我原本本没想降维打击
//zmjjkk 
