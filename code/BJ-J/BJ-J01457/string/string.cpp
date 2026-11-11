#include<bits/stdc++.h>
using namespace std;
int n;
string s;
long long ans=0;
struct node
{
	long long a;
	char c;
}b[200002];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i].a>>b[i].c;
		for(int j=1;j<=b[i].a;j++)
		{
		  s+=b[i].c;
    }
  }
  for(int i=0;i<s.size();i++)
  {
	  if(s[i]!=s[s.size()-2]) ans++;
  }
  if(ans<=s.size()/2) cout<<ans;
  else cout<<s.size()/2;
	return 0;
}