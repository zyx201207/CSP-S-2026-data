#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout); 
	int n,sum=0;
	cin>>n;
	string b;
	for(int i=1;i<=n;i++)
	{
		int a;
		char s;
		cin>>a>>s;
		while(a--)
		{
			b+=s;
		}
	}
	if(n==1) 
	{
		cout<<"0";
		return 0;
	}
	else
	{
		for(int i=0,j=b.size()-1;i<b.size(),j>=0;i++,j--)
		{
			if(b[i]!=b[j]) sum++;
		}
	}
	cout<<sum/2;
} 
