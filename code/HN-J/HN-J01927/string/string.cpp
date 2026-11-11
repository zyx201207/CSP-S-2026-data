#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a,b=0,c=0,d=0;
	cin>>a;
	long long a1[a];
	char a2[a];
	string s;
	for(long long i=0;i<a;i++)
	{
		cin>>a1[i]>>a2[i];
		c+=a1[i];
		for(long long h=0;h<a1[i];h++)
		{
			s[b]=a2[i];
			b++;
		}
	} 

	c--;
	for(int i=0;i<=c;i++)
	{
		if(c-i<=i){
			break;
		}
		if(s[i]!=s[c-i])
		{
			d+=1;
		}
		
	}
	cout<<d;
	return 0;	
} 
