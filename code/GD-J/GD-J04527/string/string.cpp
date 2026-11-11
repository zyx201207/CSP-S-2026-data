#include<bits/stdc++.h>
using namespace std; 
long long f(string s)
{
	long long i=0,j=s.size()-1,sum=0;
	while(i<=j)
	{
		if(s[i]!=s[j])
			sum++;
		i++,j--;
	}
	return sum;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long t;
	cin>>t;
	string s="";
	while(t--)
	{
		long long a;
		string b;
		cin>>a>>b;
		while(a--) s+=b;
	}
	cout<<f(s);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3
2 a
2 b
1 c
*/
