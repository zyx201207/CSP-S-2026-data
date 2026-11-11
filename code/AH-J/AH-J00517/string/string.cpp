#include <bits/stdc++.h>
using namespace std;
long long n,a[200000005],js=0,c;
bool s;
string b;
string shuai;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++)
			shuai+=b[i];
		c+=a[i];
	}
	for(int i=1;i<=c;i++)
	{
		if(shuai[i]==shuai[i-1]&&i>1)
		{
			s=1;
		}
		else s=0;
		if(shuai[i]!=shuai[c-i+1])
		{
			shuai[c+1-i]=shuai[i];
			js+=1;
		}
	}
	if(s==1)
	js=0;
	cout<<js;
	return 0;
}
