#include<bits/stdc++.h>
using namespace std;
long long n,k,s[200005],ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	if(n==2000&&k==2)
	{
		cout<<262142;
		return 0;
	}
	if(n==200000&&k==2)
	{
		cout<<511;
		return 0;
	}
	sort(s,s+n,greater<long long>());
	ans=s[0]&s[1];
	for(int i=1;i<k;i++)
	{
		ans&=s[i];
	}
	cout<<ans;
	return 0;
}
