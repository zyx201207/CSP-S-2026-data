#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
#define int long long
int n,a,ans,l;
string s;
char c;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		
		cin>>a>>c;
		l+=a;
		for(int j=1;j<=a;j++)	s+=c;
	}
//	for(int i=1;i<s.size();i++)
//	{
//		cout<<s[i];
//	}
	for(int i=((l+1)/2);i<=l;i++)
	{
		if(s[i]!=s[n-i+1])	ans++;
	}
	cout<<ans<<endl;
	return 0;
} 

/*
3
2 a
2 b
1 c
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
