#include<iostream>
using namespace std;
int n;
struct str
{
	int a;
	char c;
}s[200005];
long long q;
string f;
long long sum;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].a>>s[i].c;
		q+=s[i].a;
		for(int j=0;j<s[i].a;j++)
		{
			f+=s[i].c;
		}
	}
	int q=f.length();
	for(int i=0;i<=q/2;i++)
	{
		if(f[i]!=f[q-i-1])
		{
			sum++;
		}
	}
	cout<<sum;
}
