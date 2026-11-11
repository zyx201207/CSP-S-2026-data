#include<bits/stdc++.h>
using namespace std;
int n,m,ans=-1;
long long a[200005],f[200005];
bool b[200005];
void dfs(int x,int y){
	if(x==m+1){
		ans=max(ans,y);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			b[i]=1;
			dfs(x+1,y&a[i]);
			b[i]=0;
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
	for(int i=1;i<=n;i++){
		if(!b[i]){
			b[i]=1;
			dfs(2,a[i]);
			b[i]=0;
		}
	}
	cout<<ans;
	return 0;
}
