#include<bits/stdc++.h>
using namespace std;
long long n,m[200005];
char p;
string s1;
int huiwen(string l)
{
	int f=1,sz=l.size();
	for (int i=0;i<sz/2;i++)
	{
		if(l[i]!=l[sz-i-1])	
		{
			f=0;
			break;
		}
	}
	return f;
}
int main()
{
	int s=0,q;
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>m[i]>>p;
		for (int i=1;i<=m[i];i++)
		{
			s1+=p;
		}
	}
	q=s1.size();
	if(n==1)              
	{
		cout<<0<<endl;
		return 0;
	}
	if(huiwen(s1)==1)
	{
		cout<<0<<endl;
		return 0;
	}
	for (int i=0;i<q/2;i++)
	{
		if(s1[i]!=s1[q-i-1])	
		{
			s++;
		}
	}
	cout<<s<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}