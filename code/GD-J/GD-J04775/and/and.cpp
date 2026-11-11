#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans=-1;
bool v[200005];
void dfs(int x,long long sum){
	if(x==m+1){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			if(x==1){
				dfs(x+1,a[i]);
			}
			else{
				dfs(x+1,sum&a[i]);
			}
			v[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}
