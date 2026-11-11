#include <bits/stdc++.h>
using namespace std;
int main()
{
	ifstream cin;
	ofstream cout;
	cin.open("string.in");
	cout.open("string.out");
	long long n;
	cin>>n;
	long long a;
	char b;
	string s;
	for(long long i =0;i<n;i++)
	{
		cin>>a>>b;
		for(long long j=0;j<a;j++)
		{
			s+=b;
		}
	}long long sum=0;
	//cout<<s<<endl;
	for(long long i =0;i<s.size()/2;i++)
	{
		//cout<<s[i]<<" "<<s[s.size()-i-1]<<endl;
		if (s[i]!=s[s.size()-i-1])
		{
			//cout<<"d";
			sum+=1;
			s[n-1]=s[i];
		}
	}cout<<sum;
	return 0;
 } 
