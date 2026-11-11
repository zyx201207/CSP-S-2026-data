#include<iostream>
#include<vector>
using namespace std;

int n,m,a[300005];
int f[300005];
int num[300005];
int s[300005];
int main()
{
	for(int i=0;i<=300000;i++)f[i]=0;
	for(int i=0;i<=300000;i++)num[i]=0;
	for(int i=0;i<=300000;i++)s[i]=0;
	for(int i=0;i<=300000;i++)a[i]=0;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=s[0];j++)s[j]=0;
		for(int j=1;j<=300000;j++)f[j]=0;
		s[0]=1;
		for(int j=i;j<=n;j++)
		{
			if(f[a[j]]<=0)
			{
				s[s[0]++]=a[j];
				f[a[j]]+=1;
			}
			else 
			{
				while(s[s[0]]!=a[j] and s[0])
				{
					f[s[s[0]]]--;
					s[s[0]--]=0;
				}
				s[s[0]++]=a[j];
			}
		}
		for(int j=1;j<=s[0];j++)num[s[j]]++;
	}
	for(int i=1;i<=m;i++)cout<<num[i]<<" ";
}

