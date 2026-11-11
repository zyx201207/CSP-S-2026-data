#include <bits/stdc++.h>
using namespace std;
int a,n,len,num;
string b,s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a >> b;
		len+=a;
		for(int j=1;j<=a;j++)
		{
			s+=b;
		}
	}
	for(int i=0;i<len/2;i++)
	{
		if(s[len-1-i]!=s[i])num++;
	}
	cout << num;
	return 0;
}
