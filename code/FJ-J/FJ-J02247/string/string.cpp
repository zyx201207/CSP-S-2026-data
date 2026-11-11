#include<bits/stdc++.h>
using namespace std;
long long n,x,cnt,f[100005];
char ch,cs[10005];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>ch;
		f[ch]++;
		if(f[ch]==0) cnt=cnt+x;
	}
	cout<<cnt;
	return 0;
}
