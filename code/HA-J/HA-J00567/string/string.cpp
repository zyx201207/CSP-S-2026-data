#include<bits/stdc++.h>
using namespace std;
int n;
long long sum;
string ss="";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1,a;i<=n;i++)
	{
		char s;
		cin>>a>>s;
		for(int j=1;j<=a;j++)
			ss+=s;
	}
	if(ss.size()%2!=0)
	{
		for(int l=ss.size()/2-1,r=ss.size()/2+1;l>=0,r<ss.size();l--,r++)
			if(ss[l]!=ss[r])
				sum++;
	}
	else
	{
		for(int l=ss.size()/2-1,r=ss.size()/2;l>=0,r<ss.size();l--,r++)
			if(ss[l]!=ss[r])
				sum++;
	}
	cout<<sum;
	return 0;
}
