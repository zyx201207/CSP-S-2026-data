#include<bits/stdc++.h>
using namespace std;
long long n,d,l=0,r,cnt=0;
string s,t;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>d>>t;
		for(int j=1;j<=d;j++) s+=t;
	}
	r=s.size()-1;
	while(l<r)
	{
		if(s[l]!=s[r]) cnt++;
		l++;
		r--;
	}
	cout<<cnt;
	return 0;
}
