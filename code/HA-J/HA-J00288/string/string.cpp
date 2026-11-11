#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int cnt,ans;
int a,n;
char c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	while(n--)
	{
		cin>>a>>c;
		ans+=a;
		for(int i = 1;i<=a;i++)
		{
			s1+=c;
		}
	} 
	s2 = s1;
	reverse(s2.begin(),s2.end());
	if(s1 == s2)
	{
		cout<<0;
	} 
	else
	{
		int b = (ans+1)/2,c = s1.size()-1;
		for(int i = 0;i<b;i++)
		{
			if(s1[i]!=s1[c])
			{
				cnt++;
			}
			c--;
		}
		cout<<cnt;
	}
	return 0;
} 
