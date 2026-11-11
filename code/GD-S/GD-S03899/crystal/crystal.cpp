#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long n,m,b;
long long a[N],vis[N];
long long ans,c,d;
int main()
{
	//Ì°ÐÄ£¿ 
	//s::sync_with_std(0),cin.tie(0),cout.tie(0);//´æÒÉ 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	 } 
	 sort(a+1,a+1+n);
	while(m)
	{
		sort(a+1,a+1+n);
		a[1]++;
		m--;
	}
	c=a[1];
	for(int i=1;i<=n;i++)
	{
		if(a[i]==c)
		{
			ans++;
		}
		else break;
	}
	cout<<ans;
	 
	 
	
	return 0;
 } 
