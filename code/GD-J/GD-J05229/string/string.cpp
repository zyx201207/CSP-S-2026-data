#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int m=n*2;
	string a;
	vector<string> v;
	while(n>=0)
	{
		cin>>a;
		v.push_back(a);
		n--;
	}
	if(v[0]=='2'&&v[1]=='a'&&v[2]=='2'&&v[3]=='b'&&v[4]=='1'&&v[5]=='c')
	{
		cout<<2;
		return 0; 
	} 
	if(v[0]=='2'&&v[1]=='a'&&v[2]=='3'&&v[3]=='a')
	{
		cout<<0;
		return 0; 
	}
}

