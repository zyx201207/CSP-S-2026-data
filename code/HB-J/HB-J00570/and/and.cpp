#include<bits/stdc++.h>
using namespace std;
#define int long long
const int A=2e5;
int n,m,mx=INT_MIN,a[A];
void dfs(int x,int step,int s){
	if(step>=m) return;
	if(step==m-1){
		mx=max(mx,s);
		return;
	}
	for(int i=x+1;i<=n;i++){
		dfs(i,step+1,s&a[i]);
		dfs(i,step,s);
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dfs(i,0,a[i]);
	}
	cout<<mx;
	return 0;
}
