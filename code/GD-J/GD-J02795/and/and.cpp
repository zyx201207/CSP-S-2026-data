#include<bits/stdc++.h>
using namespace std;
int c,n,b[1000000],k,mx;
int a[1000005],v[1000005];
void dfs(int s,int f)
{
	if(f==k)
	{
		if(s>mx) mx=s;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(v[i]==0)
		{
		v[i]=1;	
		dfs(a[i]&s,f+1);
		v[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>k;
    cout<<k<<endl;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		v[i]=1;
		dfs(a[i],1);
		v[i]=0;
	}
	cout<<mx;
	return 0;
} 
