#include <bits/stdc++.h>
using namespace std;
char p[100005],pp[100005];
int main()
{	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,s=0,ks=0;
	cin>>n;
	long long ss=0;
	long long a[10000];
	for (int i=0;i<n;i++)
	{ 
		cin>>a[i]>>p[i];
		ss += a[i];
		for (int j=ks;j<ss;j++)
		{
			pp[j] = p[i];
		}
		ks +=a[i];
	}
	int sss= ss;
	for (int i=0;i<ss/2;i++)
	{
		for(int j=sss-1;j>=ss/2;j--)
		{
			if (pp[i]!=pp[j])
			{
				s++;
				sss--;
				break;
			}
			else{
				sss--;
				break;
			}
		}
	}
	cout<<s;
	freopen(stdin);
	freopen(stdout);
	return 0;
}
