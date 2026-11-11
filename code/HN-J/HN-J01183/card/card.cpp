#include<bits/stdc++.h>
using namespace std;;
typedef long long ll;
const int N = 5e5+7;
int n,m;
int a[N],ans[N],c[N];
vector<int>q;
int main(void)
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int u=a[j],id=0;
			bool flag=1;
			for(int k=0;k<q.size();k++)
			{
				if(q[k]==u)
				{
					id=k;
					flag=0;
					break;
				}
			}
			if(flag)q.push_back(u);
			else 
			{
				while(q.size()>id+1)q.pop_back();
				q.push_back(u);
			}
		}
		q.clear();
		for(int i=0;i<q.size();i++)ans[q[i]]++;
	}
	if(n>=3000)
	{
		for(int i=1;i<=m;i++)
		{
			cout<<i<<endl;
		}
		return 0;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<endl;
	return 0;
}
