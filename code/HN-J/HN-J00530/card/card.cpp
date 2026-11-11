#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int tong[500050];
int a[700070];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);	
	cin>>n>>m;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		tong[a[i]]+=i;
	} 	
	string k="";
	for(int i=n;i>=1;i--)
	{
		char t=a[i]+'0';
		k=t+k;
		for(int j=1;j<=n-i;j++)
		{
			if(k[0]==k[j])
			{
				for(int p=0;p<=j-1;p++)
				{
					tong[k[p]-'0']--;
				}
			}
		}
	} 
	for(int i=1;i<=m;i++)
	{
		cout<<tong[i]<<" ";
	}
	return 0;
}

