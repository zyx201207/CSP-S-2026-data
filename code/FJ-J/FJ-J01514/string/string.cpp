#include<bits/stdc++.h>
using namespace std;
long long zl;
long long l;
long long ans;
char c;
string str="";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>l>>c;
		zl+=l;
		for(long long j=1;j<=l;j++) str+=c;
	}
	for(long long i=0;i<zl/2;i++)
	{
		if(str[i]!=str[zl-1-i]) ans++;
	}
	cout<<ans;
	return 0;
}
