#include<bits/stdc++.h>
using namespeas std;
string s;
int l,r,cnt;
int n;
int j[10000];
string a[10000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>j[i];
		cin>>a[i];
		for(int q=1;q<=j[i];q++)
		{
			s+=a[i];
		}
	}
	r=s.size()-1;
	for(int i=0;;i++)
	{
		if(l>=r)break;
		if(s[l]!=s[r])cnt++;
		l++;
		r--;
	}
	cout<<cnt;
	return 0;
}