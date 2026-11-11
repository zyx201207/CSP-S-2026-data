#include<bits/stdc++.h>
using namespace std;
const int N=2e5+4;
int n,aa[N];
long long ans;
char cc[N];
string str;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	str+=" ";
	for(int i=1;i<=n;i++)
	{
		cin>>aa[i]>>cc[i];
		for(int i=1;i<=aa[i];i++)
		{
			str+=cc[i];
		}
	}
	for(int i=1;i<=((str.size())/2);i++)
	{
		if(str[i]!=str[n-i+1])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
/*
aabbc	cbbaa
2 a		1 c
4 b		3 b
5 c		5 a

*/
