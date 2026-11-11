#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5,M=3e5+5;
ll n,m,a[N],stk[N],top=0,ans[M];
bool f[M],A=1;
void solve()
{
	for(int i=1;i<=n;i++)
	{
		memset(f,0,sizeof(f));
		top=0;
		for(int j=i;j<=n;j++)
		{
			ll k=a[j];
			if(f[k]==1)
			{
				while(stk[top]!=k)
				{
					f[stk[top]]=0;
					top--;
				}
			}
			else
			{
				stk[++top]=k;
				f[k]=1;
			}
		}
		for(int l=1;l<=top;l++)
		{
			ans[stk[l]]++;
		}
	}
	return;
}
void solveA()
{
	for(int i=1;i<=n;i++)
	{
		memset(f,0,sizeof(f));
		top=0;
		for(int j=i;j<=n;j++)
		{
			ll k=a[j];
			if(f[k]!=1)
			{
				stk[++top]=k;
				f[k]=1;
			}
		}
		for(int l=1;l<=top;l++)
		{
			ans[stk[l]]++;
		}
	}
	return;
}

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1])A=0;
	}
	if(A)solveA();
	else solve();
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}
