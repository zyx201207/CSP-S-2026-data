#include<bits/stdc++.h>
using namespace std;
long long n,x[200010],f[30],xx,ans;
char c[200010];
bool check()
{
	for(int i=1,j=n;i<j;i++,j--)
	{
		if(c[i]!=c[j]||x[i]!=x[j])return 0;
	}
	return 1;
}
void mj()
{
	
	for(int i=1,j=n;i<j;)
	{
		if(c[i]!=c[j]||x[i]!=x[j])
		{
			if(x[i]==x[j])
			{
				c[j]=c[i];
				ans+=x[i];
				i++,j--;
			}
			else
			{
				if(x[j]<=x[i])
				{
					int pp=x[i];
					while(pp>0)
					{
						if(pp-x[j]>=0)
						{
							c[j]=c[i];
							pp-=x[j];
							ans+=x[j];
						}
						else 
						{
							ans+=pp;
							x[j]-=pp;
							pp=0;
						}
						j--;
					}
					i++;
				}
				else
				{
					int pp=x[j];
					while(pp>0)
					{
						if(pp-x[i]>=0)
						{
							c[i]=c[j];
							pp-=x[i];
							ans+=x[i];
						}
						else 
						{
							ans+=pp;
							x[i]-=pp;
							pp=0;
							i++;
						}
					}
					j--;
				} 
			}
		}
	}
} 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>c[i];
		f[c[i]-'a'+1]+=x[i];
		xx+=x[i];
	}
	if(f[c[1]-'a'+1]==xx)
	{
		cout<<0;
		return 0;
	}
	if(check())
	{
		cout<<0;
		return 0;
	}
	mj();
	cout<<ans;
	return 0;
} 
