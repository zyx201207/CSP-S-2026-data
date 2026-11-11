#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005],f[200005],f2[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int k=1;k<=n;k++)
	{
		stack<long long>q;
		memset(f,0,sizeof(f));
		//long long p=k;
		for(int i=k;i<=n;i++)
		{
			while(f[a[i]]!=0)
			{
				f[q.top()]--;
				q.pop();
			}
			q.push(a[i]);
			f[a[i]]++;
		}
		while(!q.empty())
		{
			f2[q.top()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<f2[i]<<" ";
	}
	return 0;
}
