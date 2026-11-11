#include <bits/stdc++.h>
using namespace std;
int main()
{
	//ios::sync_with_stdio(false);cin.tie(nullptr);
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	int n;string s="";
	cin >> n;
	for(int i =0;i<n;i++)
	{
		long long j;cin >> j;
		char c;cin >> c;
		for(long long z=0;z<j;z++)s+=c;
	}
	long long a=s.size();
	long long sum = 0;
	for(long long i = 0;i < a/2;i++)
	{
		if(s[i]!=s[a-1-i])sum ++;
	}
	cout << sum;
	return 0;
}
