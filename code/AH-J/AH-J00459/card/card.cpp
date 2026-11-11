#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5,M=3e5+5;
int n,m;
int a[N],ans[M];
bool flag[M];
stack <int> stk;
int main()
{
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(flag,0,sizeof flag);
		while(!stk.empty()) stk.pop();
		for(int j=i;j<=n;j++)
		{
			if(flag[a[j]])
			{
				while((!stk.empty())&&stk.top()!=a[j]) stk.pop();
			}
			else
			{
				stk.push(a[j]);
				flag[a[j]]=1;
			}
		}
		while(!stk.empty())
		{
			ans[stk.top()]++;
			stk.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
