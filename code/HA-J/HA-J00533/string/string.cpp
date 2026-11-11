#include<bits/stdc++.h>
using namespace std;
string s;
long long a,n,k=0,sum;
char c;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		{
			s[k]=c;
			k++;
		}
	}
	k-=2;
	for(int i=0;i<k;i++)
	{
		if(s[i]!=s[k+1-i])
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
