#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin)
    freopen("string.out","w",stdout)
	string s;
	int q;
	cin>>q;
	int max=1;
	int change=0;
	for(int i=1;i<=q;i++)
	{
		int u;
		string p;
		cin>>u>>p;
		for(int j=1;j<=u;j++)
		{
		    s+=p;
			max++;
		}
		
	}
	if(max%2==1)
	{
		for(int i=1;i<=(max-1)/2;i++)
		{
			if(s[i]!=s[max-i])
			{
				change++;
			}
		}
	}
	else
	{
		for(int i=1;i<max/2;i++)
		{
			if(s[i]!=s[max-i])
			{
				change++;
			}
		}
	}
	cout<<change;
	return 0;
} 
