#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string ss="";
	for(int i=1;i<=n;i++)
	{
		int a;
		string s;
		cin>>a>>s;
		for(long long j=1;j<=a;j++) ss+=s;
	}
	long long j=ss.size()-1;
	long long sum=0;
	for(long long i=0;i<ss.size() && i!=j;i++,j--)
	{
		if(ss[i]!=ss[j]) sum++;
	}
	cout<<sum;
	return 0;	
} 
