#include<bits/stdc++.h>
using namespace std;
long long s[200005],sum[1000];
char ch[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,i,j,x=0,y=0,z=1;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>s[i];
		cin>>ch[i];
	}
	i=1;j=n;
	while(i<j)
	{
		z=1;
		if(ch[i]==ch[j])
		{
			if(s[i]==s[j])
			{
				i++;
				j--;
				continue;
			}
			else if(s[i]>s[j])
			{
				s[i]=s[i]-s[j];
				j--;
				continue;
			}
			else
			{
				s[j]=s[j]-s[i];
				i++;
				continue;
			}
		}
		else
		{
			if(s[i]==s[j])
			{
				i++;
				j--;
				y=s[i];
				sum[1]+=y;
				while(sum[z]>=10)
				{
					y=sum[z]/10;
					sum[z+1]+=y;
					sum[z]-=y*10;
					z++;	
				}
				continue;
			}
			else if(s[i]>s[j])
			{
				s[i]=s[i]-s[j];
				y=s[j];
				sum[1]+=y;
				while(sum[z]>=10)
				{
					y=sum[z]/10;
					sum[z+1]+=y;
					sum[z]-=y*10;
					z++;	
				}
				j--;
				continue;
			}
			else
			{
				s[j]=s[j]-s[i];
				y=s[i];
				sum[1]+=y;
				while(sum[z]>=10)
				{
					y=sum[z]/10;
					sum[z+1]+=y;
					sum[z]-=y*10;
					z++;	
				}
				i++;
				continue;
			}
		}
	}
	for(i=990;i>=1;i--)
	{
		if(sum[i]!=0)
		{
			for(j=i;j>=1;j--)
			{
				cout<<sum[j];
			}
			return 0;
		}
		if(i==1&&sum[i]==0)
		{
			cout<<"0";
			return 0;
		}
	}
	return 0;
}
