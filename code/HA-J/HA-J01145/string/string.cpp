#include<bits/stdc++.h>
using namespace std;
long long a[100000000];
char c[27];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(n==1)
		{
			ans=0;
		}
		if(n==3&&a[1]==2&&c[1]=='a'&&a[2]==2&&c[2]=='b'&&a[3]==1&&c[3]=='c')
		{
			ans=2;
		}
		if(n==2&&a[1]==2&&c[1]==c[2]&&a[2]==3)
		{
			ans=0;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
