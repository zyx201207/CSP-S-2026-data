#include<bits/stdc++.h> 
using namespace std;
long long n,m,a[1000000],vis[1000000],s[1000000],t=0;
void print()
{
	sort(s+1,s+t+1);
	cout<<s[t];
}
void dfs(long long x)
{
	for(int j=1;j<=n;j++)
	{
		if(!vis[a[x]]&&x!=j)
		{
			t++;
			s[t]=a[x] and a[j];
			vis[a[x]]=true;
			if(x==m)
				print();
			else
				dfs(x+1);
			t--;
			s[t]=0;
			vis[a[x]]=false;	
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1);
	return 0;
}
