#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],c[200005];
string b[200005];
string tentotwo(int x)
{
	string s="";
	while(x>0)
	{
		s+=(x%2+'0');
		x/=2;
	}
	reverse(s.begin(),s.end());
	return s;
}
int frontbin(string s)
{
	long long dis=1,cnt=0;
	for(int i=0;i<s.length();i++) dis*=2;
	dis/=2;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='0') return cnt;
		cnt++;
	}
	return cnt;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) b[i]=tentotwo(a[i]);
	for(int i=1;i<=n;i++) c[i]=frontbin(b[i]);
	sort(c+1,c+n+1);
	long long ans=c[1];
	for(int i=2;i<=m;i++) ans=(c[i]&ans);
	cout<<ans;
	return 0;
}
