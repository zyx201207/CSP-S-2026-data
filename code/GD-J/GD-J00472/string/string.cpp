#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
string str;
int a[N];
char b[N];
int n,ans;
signed main()
{
	 freopen("string.in","r",stdin);
	 freopen("string.out","w",stdout);
	 ios::sync_with_stdio;
	 cin.tie(0);
	 cout.tie(0);
	 cin>>n;
	for(int i=1;i<=n;i++)
	{
	 	cin>>a[i]>>b[i];
		for(int i=1;i<=a[i];i++)
			str+=b[i];
	}
	str=" "+str;
	for(int i=1;i<=str.size()/2;i++)
		if(str[i]!=str[n-i+1])
			ans++;
	cout<<ans;
	return 0;
}

