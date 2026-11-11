#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,a[N],len=0;
char c[N];
string s;
bool flag=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		len+=a[i];
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=s[i+1]) flag=1;
	}
	if(flag==1) cout<<0;
	return 0;
}
