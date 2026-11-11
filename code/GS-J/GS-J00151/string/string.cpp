#include<bits/stdc++.h>
using namespace std;
int a[1000005];
char c[1000005];
bool sg(string s)
{
	int n=s.length();
	string t="";
	for(int i=n-1;i>=0;i--)
	{
		t+=s[i];
	}
	if(t==s) return true;
	else return false;
}
string dg(string s)
{
	int n=s.length();
	string t="";
	for(int i=n-1;i>=0;i--)
	{
		t+=s[i];
	}
	return t;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,num=0;
	cin >> n;
	string s;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i]>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		int t=a[i];
		for(int j=1;j<=t;j++) s+=c[i];
	}
	if(sg(s)==true) 
	{
		cout << 0; 
		return 0;
	}
	long long mid=s.length()/2+1;
	string t;
	if(s.length()%2==0)
	{
		for(int i=mid;i<=s.length();i++)
		{
			t+=s[i];
		}
	}
	else
	{
		for(int i=mid+1;i<=s.length();i++)
		{
			t+=s[i];
		}
	}
	string h=dg(t);
	for(int i=0;i<mid-1;i++)
	{
		if(s[i]!=h[i]) num++;
	 } 
	 cout << num;
}
