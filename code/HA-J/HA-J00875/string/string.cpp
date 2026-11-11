#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,num=0,sum=0,x;
char s;
string S;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>a>>s;
		for(ll k=1;k<=a;k++)
		{
			x++;
			S[x]=s;
		}
		num+=a;
	}
	for(ll q=1;q<=num/2;q++)
	{
		if(S[q]!=S[num-q+1])
			sum++;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

