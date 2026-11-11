#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],mx;
void dfs(long long x,long long num,long long p){//第几个，总和，选了几个 
	if(p==m){
		mx=max(mx,num);
		return;
	}
	if(x>n){
		return;
	}
	if(num<mx){
		return;
	}
	dfs(x+1,num,p);
	dfs(x+1,num&a[x],p+1);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,2147483647,0);
	cout<<mx;
	

	return 0;
}

