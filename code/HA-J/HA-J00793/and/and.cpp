#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,maxx=-1;
int a[200005];
void dfs(int id,int cnt,int sum){
	if(id>n||cnt<=0){
		if(cnt==0)
			maxx=max(maxx,sum);
		return;
	}
	if(sum==-1)
		dfs(id+1,cnt-1,a[id]);
	else 
		dfs(id+1,cnt-1,sum&a[id]);
	dfs(id+1,cnt,sum);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1,m,-1);
	cout<<maxx<<endl;
	return 0;
}
