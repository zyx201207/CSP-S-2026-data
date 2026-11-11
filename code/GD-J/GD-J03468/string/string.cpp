#include<bits/stdc++.h>
using namespace std;
long long n;
string s;
long long ans;
long long l;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long a[n+5];
	char c[n+5];
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		l+=a[i];
		for(long long j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	for(long long i=0;i<=l/2;i++){
		if(s[i]!=s[l-i-1])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

