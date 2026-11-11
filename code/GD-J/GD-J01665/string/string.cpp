#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
char s;
string ss="";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&m);
		cin>>s;
		while(m--)	ss+=s;
	}
	for(int i=0,j=ss.size()-1;i<j;i++,j--)
		if(ss[i]!=ss[j])	ans++;
	cout<<ans;
	
	return 0;
}
