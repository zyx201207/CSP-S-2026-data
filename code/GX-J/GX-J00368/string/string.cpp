#include<bits/stdc++.h>
using namespace std;

int n;
string ch;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a;
		string b;
		cin>>a>>b;
		for(int j=0;j<a;j++)
			ch+=b;
	}
	
	long long ab=ch.size(),m=0; 
	for(int i=0;i<ab/2;i++)
	{
		if(ch[i]!=ch[ab-1-i])
			m++;
	}
	
	cout<<m;
	
	return 0;
}

