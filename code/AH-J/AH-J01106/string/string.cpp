#include<bits/stdc++.h>
using namespace std;
long long n,l=0,cnt=0;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int t;
		string a;
		cin>>t>>a;
		while(t>0)
		{
			s+=a;
			t--;
			l+=a.size();
		}
	}
    string s1=s;
	reverse(s1.begin(),s1.end());
	if(s1==s)
	{
		cout<<0;
		return 0;
	}
	for(int i=0;i<l/2;i++)
	{
		string s1=s;
		reverse(s1.begin(),s1.end());
		if(s1==s)break;
		if(s[i]!=s[l-i-1])
		{
			cnt++;
			s[i]=s[l-i-1];
		}
	}
	cout<<cnt;
	return 0;
}
