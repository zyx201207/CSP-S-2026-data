#include <bits/stdc++.h>
using namespace std;
long long a[100000];
int m[100000];
bool b[100000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	long long n=0,c=0,ans=0; 
	cin>>n>>c;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]==a[j]){
			b[j]=1;
			break;
		}
	}
	}
		for(int i=1;i<=c;i++)
	{
		for(int j=i;j<=n;j++)
		{
			m[a[j]]++;
			if(b[j]==1)
			{
				b[j]=0;
				for(int x=1;x<=c;x++)
				{
					m[x]=0;
				}
				m[a[j]]++;
			}
		}
		cout<<m[i]<<" ";
		ans=0;
	}
	return 0; 
}
