#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=2e5+5;
int n,m,Max;
int a[N],b[N][35];
bool no[N];

void dfs(int i,int sum)
{
	if(i==0)
	{
		cout<<sum;
		return;
	}
	
	int cnt=0;
	for(int j=1;j<=n;j++)
		if(!no[j])
			cnt+=b[j][i];
			
	if(cnt>=m)
	{
		for(int j=1;j<=n;j++)
			if(b[j][i]==0)
				no[j]=1;
		dfs(i-1,sum+(1<<(i-1)));
	}
	else dfs(i-1,sum);
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	cin>>n>>m;

	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int t=a[i];
		while(t)
		{
			b[i][++b[i][0]]=t&1;
			t>>=1;
		}
		
		Max=max(Max,b[i][0]);
	}
	
	dfs(Max,0);

	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7

*/
