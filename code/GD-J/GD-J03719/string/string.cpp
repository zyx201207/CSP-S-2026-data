#include<bits/stdc++.h>
using namespace std;
struct duan
{
	int a;
	char c;
}z[200010];
string s;
int n;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int i,j,l=0,ans=0;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>z[i].a>>z[i].c;
	for(i=1;i<=n;i++)
		for(j=1;j<=z[i].a;j++)
			s[++l]=z[i].c;
	for(i=1;i<=l/2;i++)
		if(s[i]!=s[l+1-i])
			ans++;
	cout<<ans<<endl;
	return 0;
}
