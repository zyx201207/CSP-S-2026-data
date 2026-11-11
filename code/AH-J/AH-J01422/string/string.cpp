#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long a;
	char ch;
	string s="";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>ch;
		for(int j=1;j<=a;j++)
		{
			s+=ch;
		}
	}
	int j=s.size()-1,flag=1;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=s[j])
		{
			flag=0;
		}
		if(i>=j)
		{
			break;
		}
		j--;
	}
	if(flag==1)
	{
		cout<<0;
		return 0;
	}
	int cnt=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=s[j])
		{
			cnt++;
		}
		if(i>=j)
		{
			break;
		}
		j--;
	}
	cout<<cnt;
	return 0;
}
