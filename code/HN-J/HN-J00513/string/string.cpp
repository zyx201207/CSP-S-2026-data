#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string6.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,fre,cnt=0,num=0;
	string si,s;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>fre>>si;
		cnt=cnt+fre;
		for(int i=0;i<fre;i++)
		{
			s=s+si;
		}
	}
	for(int i=0;i<cnt/2-1;i++)
	{
		if(s[i]!=s[cnt-i-1])
		{
			num++;
		}
	}
	cout<<num;
	return 0;
}
