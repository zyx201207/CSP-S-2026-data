#include <bits/stdc++.h>
using namespace std;
string s="";
int n;
long long x;
string a;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>a;
		while(x--)
		{
			s+=a;
		}
	}
	int l=s.length();
	int num=0;
	for(int i=0;i<=l/2-1;i++)
	{
		if(s[i]!=s[l-1-i])
		{
			num++;
		}
	}
	cout<<num;
	return 0; 
 } 
