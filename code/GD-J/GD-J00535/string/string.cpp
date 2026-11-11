#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","W",stdout);
	long long a,sum=0,e;
	string b="",d="";
	char c;
	cin >> a;
	for(int i = 0;i<a;i++)
	{
		cin >> e >> c;
		for(int j = 0;j<e;j++)
		{
			b+=c;
		}
	}
	d=b;
	reverse(b.begin(),b.end());
	for(int i =0;i<b.size()/2;i++)
	{
		if(b[i]!=d[i])
		{
			sum++;
		}
	}
	cout << sum;
	fclose(stdin),fclose(stdout);
} 
