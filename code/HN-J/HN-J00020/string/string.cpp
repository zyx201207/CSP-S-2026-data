#include <bits/stdc++.h>
using namespace std;
int n,cnt=0;
int a[200005],b[200005];
string s,s1;
string reverse(string s)
{
	string b="";
	for(int j=s.size()-1;j>=0;j--){
		b+=s[j]; 
	}
	return b;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		string a;
		cin>>x>>a;
		for(int i=1;i<=x;i++)
			s+=a;
	}
	s1=reverse(s);
	
	if(s==s1)
		cout<<0;
	else
	{
		s1="";
		if(s.size()%2==1)
		{
			cnt=s.size()/2;
			for(int z=0;z<s.size()/2;z++){
				for(int y=s.size()-1;y>s.size()/2+1;y--)
				{
					if(s[z]==s[y])
					cnt--;
				 } 
			}
			
		}
		cout<<cnt;
	}
	return 0;
 } 
