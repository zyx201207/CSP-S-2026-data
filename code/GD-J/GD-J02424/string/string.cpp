#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s,s1,s2;
long a,b[N],q,ans=0,all=0,p=1;
char c[N];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(long i=1;i<=a;i++)
	{
		cin>>b[i]>>c[i];
		q=b[i];
		all+=q;
		for(long j=1;j<=q;j++) s+=c[i];
	}
	for(long i=1;i<=all/2;i++) s1[i]=s[i];
	for(long i=all;i<=all/2+2;i--) 
	{
		s2[p]=s[i];
		p++;
	}
	for(long i=1;i<=all/2;i++)
	{
		if(s1[i]!=s2[i]) ans++;
	}
	cout<<ans;
	return 0;
}
