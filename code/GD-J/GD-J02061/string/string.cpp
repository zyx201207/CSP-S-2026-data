#include<iostream>
using namespace std;
int n,a,ans=0;char c,suM=0;
char s[1000000000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a>>c;
		for(int i=suM;i<suM+a;i++)
		{
			s[i]=c;
		}suM+=a;
	}
	suM-=1;
		for(int i=0;i<suM;i++)
		{
			if(s[i]!=s[suM-i])
			{
				s[suM-i]=s[i];ans++;
			}
		}
	cout<<ans;
	return 0;
 }
