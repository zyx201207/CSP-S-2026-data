#include<bits/stdc++.h>
using namespace std;
long long n,ans;
string a;
int main()
{
	freopen("string.out","w",stdout);
	freopen("string.in","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		string c;
		cin>>x>>c;
		while(x--)
		{
			a+=c;
		}
	}
	for(long long i=0,j=a.size()-1;i<=a.size()/2,j>=a.size()/2;i++,j--)
	{
		if(a[i]!=a[j])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
