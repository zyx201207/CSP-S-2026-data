#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,cnt1,cnt2;
int js1,js2;
string s,sfz;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		string c;
		cin>>a>>c;
		while(a--)
		{
			s+=c;
		}
	}
	for(int i=s.size()-1;i>=0;i--)
		sfz+=s[i];
	if(s.size()%2==0)
	{
		for(int i=s.size()/2-1;i>=0;i--)
			if(sfz[i]!=s[i])cnt1++;
		int sz=s.size();
		for(int j=sz-1;sz/2;j--)
			if(sfz[j]!=s[j])cnt2++;
		cout<<min(cnt1,cnt2);
		return 0;
	}
	else if(s.size()%2==1)
	{
		for(int i=s.size()/2-1;i>=0;i--)
			if(sfz[i]!=s[i])js1++;
		int sz=s.size();
		for(int j=sz-1;j>=sz/2+1;j--)
			if(sfz[j]!=s[j])js2++;
		cout<<min(js1,js2);
		return 0;
	}
	return 0;
}
