#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[300005],x[300005];
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
		deque<int> q;
		memset(s,0,sizeof(s));
		for(int j=i;j<=n;j++)
		{
			if(s[a[j]]==0) 
			{
			   s[a[j]]=1;q.push_back(a[j]);	
			}
			else
			{
				while(q.size()!=0)
				{
				    if(q.back()==a[j]) 
				    {
				    	q.pop_back();break;
					}
					q.pop_back();
				}
				q.push_back(a[j]);
			}
		}
		while(q.size()!=0)
		{
			x[q.front()]++;
			q.pop_front();
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(i!=m) cout<<x[i]<<" ";
		else cout<<x[i];
	}
	return 0;
} 
