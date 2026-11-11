#include<bits/stdc++.h>
char s[100000000];
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n,a,sum=0,x=0,l;
	char c;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a>>c;
		sum+=a;
		for(int j=sum-a;j<sum;j++)
		{
			s[j]=c;
		}
	}
	l=strlen(s);
	for(int i=0;i<l;i++)
	{
		if(s[i]!=s[l-1-i])
		{
			x++;
		}
	}
	cout<<x/2;
	return 0;
	
	fclose(stdin);
	fclose(stdout);
}
