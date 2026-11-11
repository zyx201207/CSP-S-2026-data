#include<bits/stdc++.h>
using namespace std;
int a;
char c;
string s="";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		while (a--)
		s+=c;
	}
	for(int i=1,j=n;i<=n;i++,j--)
	{
		if(s[i]!=s[j])
		sum++;
		
	}
	cout<<sum;
	return 0;
}