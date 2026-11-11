#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a,s;
    long long n,c,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>c>>a;
		for(int i=0;i<c;i++)s+=a;
	}
	int m=s.size();
	for(int i=0;;)
	{
		if(i>m)break;
		if(s[i]!=s[m-1])
		{
			ans++;
			m--;
			i++;
		}
	}
	cout<<ans;
	return 0;
}
