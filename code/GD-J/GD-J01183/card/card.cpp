#include<bits/stdc++.h>
using namespace std;
stack<int> q;
int s[500005],sum[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(s[a[j]]==0)
			{
				s[a[j]]=1;
				q.push(a[j]);
			}
			else{
				while(q.top()!=a[j]){
					s[q.top()]=0;
					q.pop();
				}
			}
		}
		while(q.empty()==0){
					s[q.top()]=0;
					sum[q.top()]+=1;
					q.pop();
		}
		
	}
	for(int i=1;i<=m;i++)
	{
		cout<<sum[i]<<" ";
	}
	return 0;
}
