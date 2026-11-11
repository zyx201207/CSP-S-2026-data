#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],sum[300010];
bool v[300010];
queue<int> q;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(v[a[j]]==1)
			{
				while(1)
				{
					if(q.front()!=a[j])
					{
						q.pop();
					}
					else
					{
						q.push(a[j]);
						break;
					}
				}
			}
			else
			{
				q.push(a[j]);
				v[a[j]]=1;
			}
		}
		int s=q.size();
		for(int j=0;j<s;j++)
		{
			if(q.front()<=m)
			{
				sum[j]++;
				
			}
			else
			{
				q.pop();
			}
		}
		for(int i=1;i<=m;i++)
		{
			v[i]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<sum[i]<<" ";
	}
    return 0;
}    
