#include<bits/stdc++.h>
using namespace std;
long long n,ans,l;
char b[200005];
char s[10000005],s1[10000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		int c;
		cin>>c>>b[i];
		for(int j=1;j<=c;j++)
		{
			s[l]=b[i];
			l++;
		}
//		s[i]=b[i];
//		s1[--m]=b[i];
	}
	for(int i=0,j=l-1;i<l;i++,j--)
	{	
		if(s[i]!=s[j])
		{
			ans++;
		}
	}
	cout<<ans/2;
	return 0;
}
