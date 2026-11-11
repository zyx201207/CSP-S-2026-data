#include<bits/stdc++.h>
using namespace std;
stack<int> pq;
priority_queue<int,vector<int>,greater<int> > q;
int n,m,ant=0;
int a[100010];
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
		
		for(int i=1+ant;i<=m;i++)
		{
			if(pq.find(a[i])!=-1)
			{
				for(bool i=1;;i==1)
				{
					int qqq=pq.top();
					if(qqq==a[i])
					{
						i=0;
					}
					pq.pop();
				}
			}
			pq.push(a[i]);
		}
		while(!pq.empty()){
			int f=pq.top()
			q.push(f);
			pq.pop();
		}
		ant++;
	}
	int ans=0;
	int aaaa=0;
	for(int i=1;i<=n;i++)
	{
		int v=q.top();
		if(aaaa==v)
		{
			ans++;
		}
		else
		{
			cout<<ans;
			ans=0;
		}
	}
	
	if(ans!=0)
	{
		cout<<ans;
	}
	return 0;
} 
