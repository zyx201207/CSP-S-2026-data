#include <bits/stdc++.h>
using namespace std;
string s;
int n;
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
	
		char a;
		int m;
		cin>>m>>a;
		for(int j=1;j<=m;j++)
		{
			s+=a;
		}
	}
	long long sl=s.length();
	long long sll = sl;
	if(sl%2==0)
	{
		for(int i=0;i<=sl/2;i++)
		{
			if(s[i]!=s[sll-1])
			{ans++;} 
			sll--;
		
		}
	}
	else 
	{
		for(int i=0;i<=sl/2+1;i++)
		{
			if(s[i]!=s[sll-1])
			{ans++;} 
			sll--;
		
		}
	}
	if(ans==0)cout<<0;
	else cout<<ans-1;
	
	
	return 0;
 } 
