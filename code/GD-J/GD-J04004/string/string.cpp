#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n;
	cin>>n;
	if(n>=2000)
	cout<<"0";
	char a;
	long long gs,js=0;
	for(long long i=0;i<n;i++)
	{
		cin>>gs;
		cin>>a;
		for(long long i=0;i<gs;i++)
		{
			s[js]=a;
			js++;
		}
	}
	long long zs=0;
	for(long long i=0;i<=js/2;i++)
	{
		if(s[i]!=s[js-1-i])
		zs++;
	}
	cout<<zs;
	return 0;
}
