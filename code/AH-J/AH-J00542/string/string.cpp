#include<bits/stdc++.h>

using namespace std;
int n;
long long cnt;
string s;
int main()
{
	freopen("string.in",".r",stdin);
	freopen("string.out",".w",stdout);

	cin>>n;
	for(int i=1;i<=n;++i)
	{
		int a;
		char c;
		cin>>a>>c;
		while(a--)
			s.push_back(c);
	}
	//cout<<s<<"\n";
	int siz=int(s.size());
	int ans=siz/2;
	//cout<<ans<<"\n";
	for(int i=0;i<(siz/2);++i)
	{
		char c=s[siz-i-1];
		if(c==s[i])
			ans--;
	}
	cout<<ans;
	return 0;
}

