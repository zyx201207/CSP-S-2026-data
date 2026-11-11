#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string1.in","r",stdin);
	freopen("string.out","w",stdout);
	string S,NEW;
	int n,m,cnt=0;
	cin>>n>>m;
	for (int i = 0; i < n; ++i)
	{
		cin>>S[i];
	}
	for(int j=S.size()-1;j>=0;--j)
	{
		NEW+=S[j];
	}
	for (int k = 0; k < S.size(); ++k)
	{
		if (S[k]!=NEW[k])
		{
			++cnt;
		}
	}
	cout<<cnt;
	return 0;
}