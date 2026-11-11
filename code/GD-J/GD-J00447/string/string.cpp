#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char s[200005];
string s1;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	long long ans1=0;
	cin>>n;
	long long ans=0;
	for(int i=0;i<2000;i++)
	{
		cin>>a[i];
		ans+=a[i];
		cin>>s[i];
		for(int j=0;j<a[i];j++)
		{
			s1+=s[i];	
		}
	}
	for(long long i=0;i<ans/2;i++)
	{
		if(s1[i]!=s1[ans-1-i])
		{
			ans1++;
		}
	}
	cout<<min(ans1,ans/2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
