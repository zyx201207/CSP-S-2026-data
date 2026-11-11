#include <bits/stdc++.h> 
using namespace std;
long long n,num;
string a,s;
string s2;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>num>>a;
		for(int j=1;j<=num;j++) s+=a;
	}
	int len=s.size();
	int cnt=0;
	bool f=0;
	for(int i=len-1;i>=0;i--)
	{
		s2[cnt]=s[i];
		if(s2[cnt]!=s[cnt]) f=1;
		cnt++;
	}
	if(f==0) cout<<"0";
	
	return 0;
}
