#include<bits/stdc++.h>
using namespace std;

int n;
long long a[200010];
char s1[200010];
long long len1=0,n1=0,num=0;

int main()
{
	freopen("string.in","r",stdin);
	//freopen("string4.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>s1[i];
		len1+=a[i];
	}
	char s[len1+10]={0};
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<a[i];j++)
		{
			s[n1+j]=s1[i];		
		}
		n1+=a[i];
	}
	int len=strlen(s);
	/*for(int i=0;i<len;i++)
	{
		cout<<s[i];
	}*/
	for(int i=0;i<len;i++)
	{
		if(s[i]!=s[len-1-i])
		{
			//cout<<s[i]<<" "<<s[len-1-i]<<"\n";
			num++;
		}
	}
	cout<<num/2;
}
