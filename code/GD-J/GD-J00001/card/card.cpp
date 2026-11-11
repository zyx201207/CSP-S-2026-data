#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],l[300005];
bool p[300005];
deque<int>s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
 	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
 	cin>>n>>m;
 	for(int i=1;i<=n;i++)cin>>a[i];
 	for(int i=1;i<=n;i++)
 	{
 		for(int j=i;j<=n;j++)
 		{
 			if(p[a[j]]==1)
 			{
 				while(!s.empty())
 				{
 					if(s.back()==a[j])
 					{
 						break;
					}
					s.pop_back();
				}
			}
			else 
			{
				s.push_back(a[j]);
				p[a[j]]=1;
			}
		}
		while(!s.empty())
		{
			l[s.front()]++;
			s.pop_front();
		}
		memset(p,0,sizeof(p));
	}
	for(int i=1;i<=m;i++)cout<<l[i]<<" ";
	return 0;
}


