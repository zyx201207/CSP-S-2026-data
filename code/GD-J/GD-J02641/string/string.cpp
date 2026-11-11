#include<bits/stdc++.h>
using namespace std;
string s="";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,cnt=0;
	char c;
	cin>>n;
	while (n--)
	{
		cin>>a>>c;
		for (int i=1;i<=a;i++) s+=c;
	}
	int l=s.size();
	for (int i=0;i<l/2;i++)
	{
		if (s[i]!=s[l-i-1])
			cnt++;
	}
	cout<<cnt;
	return 0;
}
