#include <iostream>
using namespace std;
string s;
int cnt=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m;string a;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>m>>a;
		for (int j=1;j<=m;j++)
		{
			s+=a;
		}
	}
	int e=s.size();
	for (int i=0;i<e;i++)
	{
		if(s[i]!=s[e-i-1])
		{
			cnt++;
		}
	}
	cout<<cnt/2;
	return 0;
}

