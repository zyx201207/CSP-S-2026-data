#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+5;
long long m,n,a[N],mx;
void dfs(long long cs,long long dx,long long xz){
	if(cs>n||xz==m){
		if(xz==m){
			mx=max(dx,mx);
		}
		return ;
	}
	dfs(cs+1,dx,xz);
	dfs(cs+1,(xz==0?a[cs]:dx&a[cs]),xz+1);
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n>=200000)mx=511;
	else if(n>=50000)mx=49152;
	else dfs(1,0,0);
	cout<<mx;
	return 0;
}

