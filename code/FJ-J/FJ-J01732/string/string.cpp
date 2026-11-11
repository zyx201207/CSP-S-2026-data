#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,t,x,s,ans,a[N];
string s1="";
char y,last;
char b[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		s+=x;
		if(y==last) a[t]+=x;
		else last=y,a[++t]=x,b[t]=y;
	}
	if(t==1)
	{
		cout<<0;return 0;
	}
	if(t==2)
	{
		cout<<min(a[1],a[2]);return 0;
	}
	for(long long i=1;i<=t;i++)
		for(long long j=1;j<=a[i];j++)
			s1+=b[i];
	for(int i=0,j=s-1;i<j;i++,j--)
		if(s1[i]!=s1[j]) ans++;
	cout<<ans;
	return 0;
}
