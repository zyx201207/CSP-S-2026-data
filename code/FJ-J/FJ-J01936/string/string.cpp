#include<bits/stdc++.h>
using namespace std;
long long n;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int a[n+2];
	long long o=0;
	int y=0;
	a[0]=0;
	a[n+1]=0;
	string s[n+2];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
		o+=a[i];
		
	}
	string f[o+1];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			f[j+a[i-1]]=s[i];
		}
	}
	 for(int i=1,j=o;i<=o;i++,j--)
	 {
	 	if(f[i]!=f[j])
	 	{
	 		y++;
	 		f[j]=f[i];
		 }
	 }
	 cout<<y;
	 return 0;
}
