#include<bits/stdc++.h>
using namespace std;
int n,a,as;
string s,o;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>o;
		while(a--) s+=o;
	}
	int l=0,r=s.size()-1;
	cout<<'\n';
	while(l<=r)
	{
		if(s[l]!=s[r]) as++;
		l++,r--;
	}
	cout<<as;
	return 0;
}
