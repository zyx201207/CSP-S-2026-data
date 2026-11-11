#include<bits/stdc++.h>
using namespace std;
const int M=2*1e5+5;
int n,m,ans=0;
int a[M];
void dfs(int h,int num)
{
	if(h>m){
		ans=max(ans,num);
		return;
	}
	for(int i=h+1;i<=n;i++)
	{
		dfs(h+1,(num&a[i]));
	}
	return;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dfs(1,(a[i]&a[i+1]));
	}
	cout<<ans;
	return 0;
}
