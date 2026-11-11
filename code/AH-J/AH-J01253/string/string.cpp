#include<bits/stdc++.h>
using namespace std;
long long n,s,lena;
char x;
vector <int> a;
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
		cin>>s>>x;
		for(int j=0;j<s;j++)
		{
			a.push_back(int(x));
		}
	}
	lena=a.size();
	s=0;
	for(int i=0;i<(lena+1)/2;i++)
	{
		if(a[i]!=a[lena-i-1])
		{
			s+=1;
		}
	}
	cout<<s;
	return 0;
}
