#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],s[1000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int l=n;l>=1;l--)
	{
		for(long long j=l;j<=n;j++)
		{
			long long t=0;
			for(int i=j+1;i<=n;i++)
			{
				if(a[i]==a[j])
				{
					t=i;
					break;
				}
			}
			if(t==0)s[a[j]]++;
			if(t!=0)j=t-1;
		}
	}
	for(int i=1;i<=m;i++)cout<<s[i]<<" ";
	return 0;
} 
