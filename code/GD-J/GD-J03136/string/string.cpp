#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;
long long n,ans,len,a;
char c;

int main()
{
	freopen("string4.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string s=" ";
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c,len+=a;
		string t(a,c);
		s+=t;
	}
	long long mid=len/2;
	for(int i=1;i<=mid;i++)
	{
		if(s[i]!=s[len-i+1]) ans++;
	}
	cout<<ans<<'\n';
	return 0;
}
/* 
6
2 a
3 b
3 c
1 d
2 e
1 f
*/
