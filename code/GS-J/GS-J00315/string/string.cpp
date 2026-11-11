#include<bits/stdc++.h>
#define endl'\n'
using namespace std;

int n,sum=0, a[100000000];
char s[1010],c[10010];
string b;
int main()
{
	//freopen("string.in","r","stdin");
	//freopen("string.out","w","stdout");
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
		sum+=a[i]*a[i];
		c[sum]+=s[i];
		b=c[i];
		cout<<b;
	}
	return 0;
}
