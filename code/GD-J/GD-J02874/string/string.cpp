#include<bits/stdc++.h>
using namespace std;
long long n,a,sam,sun;
char a1;
string aa;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++)
	{
		cin>>a>>a1;
		sam += a;
		for(int j = 1;j<=a;j++)
		{
			aa += a1;
		}
	}
	for(int i = 1;i <= sam/2+1;i++)
	{
		if(aa[i] != aa[sam - i + 1])
		{
			sun++;
		}
	}
	cout<<sun;
	
	return 0;
}

