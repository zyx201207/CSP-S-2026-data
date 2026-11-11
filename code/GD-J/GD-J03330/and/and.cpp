#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2*1e5+1;
int n,m,a[N],mx=0;
void dfs(int x,int y,int z){
	if(y==m){
		mx=max(x,mx);
		return;
	} 
	if(z==n+1&&y<m){
		return;
	}
	for(int i=z;i<=n;i++){
		int c;
		c=a[i]&x;
		dfs(c,y+1,i+1);
	} 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dfs(a[i],1,i+1);
	}
	cout<<mx;
}

