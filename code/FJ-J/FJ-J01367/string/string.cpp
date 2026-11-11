#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXN=2e5+5;
int n,l,ans,a;
string s,c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a>>c;
		for(int j=0;j<a;j++)
		{
			s+=c;
		}
		l+=a;
	}
//	cout<<s<<endl<<l<<endl;
	for(int i=0;i<l/2;i++)
	{
		if(s[i]!=s[l-i-1])
		{
			ans++;
//			cout<<i<<' ';
		}
	}
	cout<<ans;
	return 0;
}//just so so
