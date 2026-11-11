#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m,k=0,sum=0;
	char a;
	string s,s1;
	cin >> n;
	for (long long i=1;i<=n;i++){
		cin >> m;
		cin >> a;
		for (long long j=1;j<=m;j++){
			s[k]=a;
			k++;
		}
	}
	long long l=(k-1)/2+1;
	for (long long i=0;i<l;i++){
		if (s[i]!=s[k-i-1]) sum++;
	}
	cout << sum;
	return 0;
}
