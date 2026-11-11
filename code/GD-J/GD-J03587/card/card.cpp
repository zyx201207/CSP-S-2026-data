#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5,M = 3e5 + 5;
int n,m;
int a[N],w[N],en[M],ans[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		en[a[i]] = i;
		w[i] = 1;
	}
 	for(int i=1;i<=n;i++)
 	{
 		w[en[a[i]] + 1] += w[i];	
		ans[a[i]] += w[i];
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i];
		cout<<' ';
//		if(i != m)
//		{
//			cout<<',';
//		}	
	} 
	return 0;
} 
