#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
long long n,num,len,ans;
char c;
string s,a;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&num);
		cin>>c;
		while(num)
		{
			s+=c;
			num--;
		}
	}
	len=s.size();
	for(int i=0,j=len-1;i<=j;i++,j--)
	{
		if(s[i]!=s[j])
			ans++;
	}
	cout<<ans;
	return 0;
}
