#include <bits/stdc++.h>
#define ll long long
using namespace std;
int read(){int x;scanf("%lld",&x);return x;}
//const int N=
//void hyw(){puts("hyw");}
ll n;
string a,b;
ll x;
ll sum;
char ch;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		x=read();
		cin>>ch;
		for(int i=1;i<=x;++i) a=a+ch;}
	b=a;
	reverse(a.begin(),a.end());
	for(int i=0;i<=a.size();++i)
	{
		if(a[i]!=b[i])sum++;
	}
	cout<<sum;
	return 0;
}
