#include<bits/stdc++.h>
using namespace std;
int n,m;
unsigned long long a[200001],mx=0;
void dfs(int i,unsigned long long b,int s){
	if(s==m){
		mx=max(mx,b);
		return;
	}
	if(i>n)
		return;
	dfs(i+1,b&a[i],s+1);
	if(n-i+s>=m)
		dfs(i+1,b,s);
}
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n-m+1;i++)
		dfs(i+1,a[i],1);
	cout<<mx;
	return 0;
}
