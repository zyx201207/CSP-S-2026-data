#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200005];
int t=0;
void dfs(int k,int z,int s){
	if(z==m){
		t=max(t,s);
		return;
	}
	for(int i=k+1;i<=n;i++){
		if(s&a[i]<t)continue;
		if(s==-1)dfs(i,z+1,a[i]);
		else dfs(i,z+1,s&a[i]);
	}
}
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	dfs(0,0,-1);
	cout<<t;
	return 0;
}
