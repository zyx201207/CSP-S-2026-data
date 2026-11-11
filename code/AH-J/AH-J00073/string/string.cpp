#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,ans;
int a[2*N];
char ch[2*N];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",a+i);
		cin>>ch[i];
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=a[i]; j++)
		{
			s+=ch[i];
		}
	}
	for(int i=0,j=s.size()-1;i<=j; i++,j--)
	{
		if(s[i]!=s[j]) ans++;
	}
	cout<<ans;
	return 0;
}
