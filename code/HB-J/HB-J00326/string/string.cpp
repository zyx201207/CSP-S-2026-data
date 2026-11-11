#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int a;
char c;
__int128 cnt;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++)s+=c;
	}
	for(int i=0;i<=int(s.size())/2-1;i++)
	{
		if(s[i]!=s[s.size()-i-1])cnt++;
	}
	string ans="";
	while(cnt)
	{
		ans=to_string(int(cnt%10))+ans;
		cnt/=10;
	} 
	if(ans=="")cout<<0;
	else cout<<ans;
	return 0;
}
