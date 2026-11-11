#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a,len,ans,p;
char c1,c2,c;
string s;
struct node{
	int l,r,t;
	char ac;
}ak[200005];
main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++) s+=c;
	}
	int m=s.size();
	for(int i=0;i<m;i++)
	{
		if(s[i]!=s[m-1-i]) ans++;
	}
	cout<<ans/2;
}
