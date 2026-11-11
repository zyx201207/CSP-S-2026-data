#include<bits/stdc++.h>
#include<string>
#define N 200005
using namespace std;
int n,l=0;
unsigned long long len=0,ans=0;
char c[N],a[N];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i]>>c[i];
	for(int i=0;i<n;i++) len+=a[i]-48;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<a[i]-48;j++,l++)
		{
			s[l]=c[i];
		}
	}
	for(unsigned long long i=0;i<len/2;i++)
	{
		if(s[i]!=s[len-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
