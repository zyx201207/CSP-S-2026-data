#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
bool f[200005];
int dfs(int x,int y){
	if(f[y]) return ans;
	if(x==m) return ans;
	for(int i=1;i<=n;i++){
		if(!f[i]&&i!=y){
			f[i]=1;
			ans&=a[i];
			dfs(x+1,i);
		}
	}
}
int main(){	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ans=a[1];
	cout<<dfs(m,1);
	return 0;
}
