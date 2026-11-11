#include<bits/stdc++.h>
using namespace std;
string s;
char s1;
long long n,m,f[205],k,ans;
void check(string ss)
{
	long long len=ss.size();
	long long l=0,r=len-1;
	while(l<r)
	{
		if(ss[l]!=ss[r]) ans++;
		l++;
		r++;
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m>>s1;
		for(int j=1;j<=m;j++)
		{
			s=s+s1;
		}
		f[s1]++;
	}
	if(n==1)
	{
		cout<<"0";
		return 0;
	}
	for(int i=0;i<=200;i++)
	{
		if(f[i]!=0) k++;
	}
	if(k==1)
	{
		cout<<"0";
		return 0;
	}
	check(s);
	cout<<ans;
	
	
	return 0;
} 
