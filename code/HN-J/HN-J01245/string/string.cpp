#include <bits/stdc++.h>
using namespace std; 
long long n,a,zz=0,s1=0;
string s;
char z;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>z;
		for(int j=1;j<=a;j++)
		{
			s[zz]=z;
			zz+=1;
		}
	}
	zz-=1;
	for(int i=0;i<=zz/2;i++)
	{
		if(s[i]!=s[zz-i]) s1++;
	}
    cout<<s1;
	return 0;
}
