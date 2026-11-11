#include<bits/stdc++.h>
using namespace std;
int t,n,l,cnt;
string s,ss="";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n>>s;
		l+=n;
		while(n--)
			ss+=s;
	}
	for(int i=0;i<l/2;i++)
	{
		int j=l-i-1;
		if(ss[i]!=ss[j])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
