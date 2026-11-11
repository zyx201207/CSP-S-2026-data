#include<bits/stdc++.h>
using namespace std;
long long n,a[10000005],sum=0,z=0;
char c[10000005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
		{
			s[z]=c[i];
			z++;
		}
	}
	if(z%2!=0)
	{
		for(int i=0;i<z/2;i++)
		{
			if(s[z/2-i]!=s[z/2+(z/2-i)])
			{
				sum++;
			}
		}
	}
	else if(z%2==0)
	{
		for(int i=0;i<z/2;i++)
		{
			double o=z/2-0.5;
			double k=o+o-i;
			int kk=k;
			if(s[i]!=s[kk])
			{
				sum++;
			}
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
