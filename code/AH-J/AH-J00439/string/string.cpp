#include<bits/stdc++.h>
using namespace std;
string s;
char c;
int n,a,ans,len,i,j;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int i=1;i<=a;i++)
		{
			s+=c;
		}
	}
	len=s.size();
	if((len-1)%2==0)
	{
		i=j=(len-1)>>1;
	}
	else
	{
		j=(len-1)>>1;
		i=j-1;
	}
	while(i>=0&&j<=len-1)
	{
		if(s[i]!=s[j])
		{
			ans++;
		}
		i--;
		j++;
	}
	cout<<ans;
	return 0;
}
