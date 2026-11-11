#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,sum=INT_MAX;
bool b[200005];
void dfs(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(!b[i])
		{
			int v=sum;
			sum=sum&a[i];
			b[i]=1;
			if(x==m)
			ans=max(ans,sum);
			else 
			dfs(x+1);
			sum=v;
			b[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	dfs(1);
	cout<<ans;
	return 0;
}
