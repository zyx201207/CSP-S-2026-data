#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+7;
long long n,ans,a[N];
string c[N];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=0;j<a[i];j++)
		{
			s+=c[i];
		}
	}
	long long l=0,r=s.size()-1;
	while(l!=r&&l<r)
	{
		if(s[l]==s[r])
		{
			l++;
			r--;
		}
		else
		{
			ans++;
			s[r]=s[l];
			r--;
			l++;
		}
	}
	cout<<ans;
}
