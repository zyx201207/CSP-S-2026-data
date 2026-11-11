#include <bits/stdc++.h>
using namespace std;
int ans;
int main()  
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;string s="";
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++) s+=c;
	}
	int sz=s.size();
	for(int i=0,j=sz-1;i<j;i++,j--) 
	{
		if(s[j]!=s[i]) ans++;
	}
	cout<<ans;
	return 0;
}
