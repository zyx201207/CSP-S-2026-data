#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010],s;
void dfs(int x,int y,int z)
{
	if(x<=s){
		return;
	}
	if(y==m){
		s=x;
	}
	if(z>n||z+m-y>n+1){
		return;
	}
	for(int i=z+1;i<=n;i++){
		dfs(x&a[i],y+1,i);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-m+1;i++){
		dfs(a[i],1,i);
	}
	cout<<s;
	return 0;
}
