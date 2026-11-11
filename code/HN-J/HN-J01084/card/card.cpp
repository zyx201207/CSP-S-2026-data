#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n;
	vector<int> a;
	cin>>n;int m;
	for(int i=1; i<=n; i++)
	{
		cin>>m;
		a.push_back(m);
	}
	queue<int> q;
	
	for(int i=1;i<=n;i++)
	{
		vector<int> v;
		int x[300005]={};
		for(int j=1;j<i;j++)
			v.push_back(0);
		for(int j=i;j<=n;j++)
		v.push_back(a[j]);
		int j=i;
		while(1)
		{
			
			if(x[v[j]]>0)
			{
				int mm=v[j];
				while(!q.empty())
				{
					v[q.front()]=0;
					q.pop();
				}
				x[mm]=0;
			}
			else
			{
				x[v[j]]++;
				q.push(v[j]);
			}
			j++;
			if(j==n)
			{
				if(x[i]>0)
				cout<<x[i]<<' ';
				break;
			}
		}
	}
	return 0;
}
