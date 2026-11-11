#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],l=0,y=1,z=0,num=0;
char c[200005];
string s=".";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		l+=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		while(a[i]!=0)
		{
			if(c[n]!=c[i])
			{
				num+=min(a[n],a[i]);
			}
			if(a[n]>a[i])
			{
				a[n]-=a[i];
				a[i]=0;
			}
			else if(a[n]==a[i])
			{
				n--;
				a[i]=0;
			}
			else
			{
				a[i]-=a[n];
				n--;
			}
		}
	}
	cout<<num;
	return 0;
}
