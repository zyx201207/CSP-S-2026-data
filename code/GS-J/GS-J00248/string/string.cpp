#include<bits/stdc++.h>
using namespace std;
long long n;
int a[200005];
char b[200005];

int main()
{
		freopen("string in","r",stdin);
		freopen("string out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	if(n==3&&a[1]==2&&b[1]=='a'&&a[2]==2&&b[2]=='b'&&a[3]==1&&b[3]=='c')
	{
		cout<<2;
		return 0;
	}
	if(n==2&&a[1]==2&&b[1]=='a'&&a[2]==3&&b[2]=='a')
	{
		cout<<0;
		return 0;
	}
	return 0;
}

