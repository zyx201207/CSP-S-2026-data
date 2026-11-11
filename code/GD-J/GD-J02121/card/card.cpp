#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+50;
ll a[N],s[N],t[N],b[N];
ll f[N]; 
bool ok;
ll n,m,ans,sum;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		t[a[i]]++;
	}	
	for(int i=1;i<n;i++)
	{
		if(a[i]>a[i+1])
		{
			ok=1;
			break;
		}
		//cout<<ok;
	}
	if(ok==0)
	{
		for(int i=1;i<=m;i++)
		{
			s[i]=s[i-1]+t[i];
			cout<<s[i]<<" "; 
		}
		return 0;
	}
	while(m>0)
	{	
	int a1[N];
	for(int k=1;k<=n;k++)
			{
				a1[k]=a[k];
			}
		for(int i=n-m;i<=n;i++)
		{
			f[i]=a[i];
			
			for(int j=1;j<=i;j++)
			{
				if(a1[j]==a1[i])
				{
					for(;j<=i;j++)
					{
						a1[j]=0;
					}
				}
			}
			
		}
		for(int i=1;i<=n;i++)
		{
			if(a1[i]!=0)
			{
				b[a1[i]]++;
			}
		}
		m--;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
