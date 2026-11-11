#include<bits/stdc++.h>
using namespace std;
char a[200010];
long long s[200010];
int n,idx;
long long sum;
int main(void)
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    int flag=0;
    for(int i=1;i<=n;i++)
    {
		cin>>s[i]>>a[i];
		idx=i;
		if(a[i]!=a[i]-1&&i>=2)
		{
			flag=1;
		}
	}
	if(flag==0)
	{
		cout<<"0";
		return 0;
	}
	for(int i=1,j=idx;i<=idx/2;i++,j--)
	{
		if(a[i]!=a[j])
		{
			if(s[i]==s[j])
			{
				sum+=s[j];
				a[i]=a[j];
			}
			else if(s[i]<s[j])
			{
				sum+=s[j];
				int sheng=s[j]-s[i];
				a[i]=a[j];
				int biao=i+1;
				while(1)
				{
					if(sheng<s[biao])
					{
						s[biao]-=sheng;
						i=biao-1;
						break;
					}
					else
					{
						a[biao]='0';
						s[biao]=0;
						biao++;
					}
				}
			}
			else if(s[i]>s[j])
			{
				sum+=s[i];
				int sheng=s[i]-s[j];
				a[j]=a[i];
				int biao=j-1;
				while(1)
				{
					if(sheng<s[biao])
					{
						s[biao]-=sheng;
						j=biao+1;
						break;
					}
					else
					{
						a[biao]='0';
						s[biao]=0;
						biao++;
					}
				}
			}
		}
		else if(a[i]==a[j])
		{
			if(i==j-1)
			{
				continue;
			}
			else if(s[i]>s[j])
			{
				sum+=s[i];
				sum-=s[j];
				int sheng=s[j]-s[i];
				a[i]=a[j];
				int biao=i+1;
				while(1)
				{
					if(sheng<s[biao])
					{
						s[biao]-=sheng;
						i=biao-1;
						break;
					}
					else
					{
						a[biao]='0';
						s[biao]=0;
						biao++;
					}
				}
			}
			else if(s[i]>s[j])
			{
				sum+=s[i];
				sum-=s[j];
				int sheng=s[i]-s[j];
				a[j]=a[i];
				int biao=j-1;
				while(1)
				{
					if(sheng<s[biao])
					{
						s[biao]-=sheng;
						j=biao+1;
						break;
					}
					else
					{
						a[biao]='0';
						s[biao]=0;
						biao++;
					}
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
