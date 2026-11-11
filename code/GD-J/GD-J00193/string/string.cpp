#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],len,t,d1,d2;
string s;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>c;
		len+=a[i];
		t=a[i];
		while(t--) s+=c;
	}
	if(len%2==0)
	{
		for(long long i=0;i<=len/2-1;i++)
		{
			if(s[i]!=s[len-i-1]) d1++;
		}
		for(long long i=len/2;i<len;i++)
		{
			if(s[i]!=s[len-i-1]) d2++;
		}
		cout<<min(d1,d2);
	}
	else if(len%2==1)
	{
		for(long long i=0;i<=len/2-1;i++)
		{
			if(s[i]!=s[len-i-1]) d1++;
		}
		for(long long i=len/2+1;i<len;i++)
		{
			if(s[i]!=s[len-i-1]) d2++;
		}
		cout<<min(d1,d2);
	}
	return 0;
}
