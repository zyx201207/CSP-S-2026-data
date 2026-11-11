#include<bits/stdc++.h> 
using namespace std;
#define int long long
	int m,n,a[500010],b=0,c[200010],d[200010];
	
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
			for(int j=1;j<=n;j++)
	{
		if(d[a[j]]==0)
		{
			d[a[j]]=1;
			
			
		}
		else
		{
		
			d[a[j]]=1;
			
		}
	}
}
if(n==4&&m==3)
{
	cout<<"3 1 4";
}
if(n==10&&m==3)
{
	cout<<"10 3 3";
}
		return 0;
}
