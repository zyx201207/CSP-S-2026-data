#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],xhd;
long long dfs(int x,int l,long long r){
	if(x+(m-l)>n){
		return -1;
	}
	if(l==m){
		return r;
	}
	long long hhh=-1;
	for(int i=x+1;i<=n;i++){
		long long hh=dfs(i,l+1,a[i]&r);
		hhh=max(hhh,hh);
	}
	return hhh;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		long long h=dfs(i,1,a[i]);
		xhd=max(xhd,h);
	}
	cout<<xhd;
	return 0;
} 
