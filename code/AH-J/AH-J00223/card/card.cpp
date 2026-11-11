#include<bits/stdc++.h>
using namespace std;
int n,m,card[500005],top,last_pos[300005],bucket[300005],q[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(NULL);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>card[i];
	}
	for(int step=1;step<=n;step++)
	{
		top=0;
		memset(last_pos,0,sizeof last_pos);
		for(int i=step;i<=n;i++)
		{
			if(last_pos[card[i]]==0)
			{
				top++;
				last_pos[card[i]]=top;
				q[top]=card[i];
			}
			else
			{
				for(int j=last_pos[card[i]]+1;j<=top;j++)
				{
					last_pos[q[j]]=0;
				}
				top=last_pos[card[i]];
			}
		}
		for(int i=1;i<=top;i++)
		{
			bucket[q[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<bucket[i]<<" ";
	}
	return 0;
}
