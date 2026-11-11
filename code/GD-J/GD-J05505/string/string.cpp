#include<bits/stdc++.h>
using namespace std;
int n;
string s;
long long ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int o=1;o<=n;o++)
	{
		int l;
		string ch;
		cin>>l>>ch;
		for(int i=1;i<=l;i++)
		{
			s+=ch;
		}
	}
	int l=0,r=(int)s.size()-1;
	while(l<r)
	{
		if(s[l]!=s[r])
		{
			ans++;
		}
		l++,r--;
	}
	cout<<ans;
	return 0;
}
