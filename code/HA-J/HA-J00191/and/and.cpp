#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int n,m;
int k=INT_MAX;
int dfs(int step,int num,int sum)
{
	if(num==m) return sum;
	if(step==n) return 0;
	sum=max(dfs(step+1,num,sum),dfs(step+1,num+1,sum&a[step+1]));
	return sum;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	cout<<dfs(0,0,k);
	return 0;
}
