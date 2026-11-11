#include <bits/stdc++.h>
using namespace std;
long long n,len,ans;
string a;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		
		int num;
		string x;
		cin>>num>>x;
		len+=num;
		while(num--) a+=x;
	}
	for(int i=0;i<=len/2;i++)
	{
		if(a[i]!=a[len-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
