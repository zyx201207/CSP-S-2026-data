#include<bits/stdc++.h>
using namespace std;
long long a,b,c[200005],d,e;
void dfs(long long i,long long s,long long cn){
	if(i>a||cn<0)return;
	if(cn==0){
		d=max(d,s&c[i]);
		return;
	}for(int j=i+1;j<=a;j++){
		dfs(j,s&c[j],cn-1);
	}return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio();cin.tie(0);cout.tie(0);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c[i];
	}dfs(0,2147483647,b);
	cout<<d;
	return 0; 
}
