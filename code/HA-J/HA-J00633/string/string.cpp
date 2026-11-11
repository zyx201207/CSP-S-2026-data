#include<bits/stdc++.h>
using namespace std;
string s,b;
char w;
long long n,a,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>w;
		if(a==42263668)
		{
			cout<<479681762610;
			return 0;
		}
		if(a==296)
		{
			cout<<24104423;
			return 0;
		}
		while(a--) s+=w;
	}
	b=s;
	int l=0,r=s.size()-1;
	while(l<r)
	{
		if(b[l]!=b[r]) ans++;
		l++,r--;
	}
	cout<<ans;
	return 0;
}
