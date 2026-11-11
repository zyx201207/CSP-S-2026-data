#include <bits/stdc++.h>
using namespace std;
long long n,cnt=1,js;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a;
	char c;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(long long j=1;j<=a;j++)
		{
			s[cnt]=c;
			cnt++;
		}
	}
	long long d=cnt/2;
	for(long long j=1;j<=d;j++)
	{
		if(s[j]!=s[d+1])
		{
			js++;	
		}
	}
	cout<<js;
	return 0;
}
