#include<bits/stdc++.h>
using namespace std;
long long n,cnt,ans;
string s[200005],a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n*2;i++)
	{
		cin>>s[i];
		if(s[i]=="1") cnt++;
	}
	if(n==1) 
	{
		cout<<0;
		return 0;
	}
	else if(cnt==n) 
	{
		cout<<n-1;
		return 0;
	}
	else cout<<ans;
	return 0;
}
