#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAX=2e5+5;
string s;
int n,ans;
int number[MAX];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int num;
		char alpha;
		cin>>num>>alpha;
		number[i]=num;
		s+=alpha;
	}
	for(int i=0;i<n;i++)
	{
		if(s[i]==s[n-i])
		{
			continue;
		}
		else ans++;
	}
	cout<<ans-1;
	return 0;
}
