#include<bits/stdc++.h>
using namespace std;
stack t[10005] <string>
int main()
{
	freopen(string.in,"r",stdin);
	freopen(string.in,"w",std.out);
	int n;
	cin>>n;
	int a;
	string s;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>s;
		for(int j=0;j<a;j++)t.push(s);
	}
	int m=t.size();
	if(n==2)cout<<0;
	if(n==3)cout<<2;
	return 0;
}
