#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int ans;
void dfs(int k,int dep,int sum){
	if(dep>=m){
		ans=max(ans,sum);
		return;
	}
	for(int i=k+1;i<=n-m+dep+1;i++)
		dfs(i,dep+1,sum&a[i]);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	dfs(0,0,(1<<30)-1);
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
