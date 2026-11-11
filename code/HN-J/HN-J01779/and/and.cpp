#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,ans,ma=-1;
int a[N],f[N];
void dfs(int x,int y,int l){
	if(x==m){
		ma=max(ma,l);
		return;
	}
	if(y>n)return;
	for(int i=y;i<=n;i++){
		dfs(x+1,i+1,l & a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	ans=(1<<31)-1;
	dfs(1,1,ans);
	cout << ma;
	return 0;
}
