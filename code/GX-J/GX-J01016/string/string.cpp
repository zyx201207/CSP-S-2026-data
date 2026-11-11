#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
long long n,x,ans;
string s,c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>x;
		cin>>c;
		while(x--)		
			s=s+c;
	}
	long long len=s.size();
	for(int i=0,j=len-1; i!=j; i++,j--)
		if(s[i]!=s[j])
			ans++;
	cout<<ans;		
	return 0;
}

