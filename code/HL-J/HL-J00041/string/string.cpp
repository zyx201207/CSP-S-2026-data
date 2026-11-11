#include <bits/stdc++.h>
using namespace std;
string s;
long long a[200011];
char c;
long long n,sum=0,len=0;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(long long i=1;i<=n;i++)
	{
		cin >> a[i] >> c;
		for(long long j=len+1;j<=len+a[i];j++)
		{
			s[j]=c;
		}
		len+=a[i];
	}
	for(long long i=1;i<=len;i++)
	{
		if(s[i]!=s[len-i+1])
		{
			s[i]=s[len-i+1];
			sum++;
		}
	}
	cout << sum;
	return 0;
}
