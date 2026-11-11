#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,a[200005],t,len,ans;
char ch;
string str;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	str=' ';
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>ch;
		len+=a[i];
		for(int j=1;j<=a[i];j++) str=str+ch;
	}
	for(int i=1;i<=len-i+1;i++)
	{
		if(str[i]!=str[len-i+1]) ans++;
	}
	cout<<ans;
	return 0;
}//f(x)=kx+b,f'(x)=lim(t->0)(k(x+t)+b-(kx+b))/t=(kx+kt+b-kx-b)/t=kt/t=k
