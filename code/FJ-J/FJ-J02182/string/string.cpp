#include<bits/stdc++.h>
using namespace std;
long long n,a,i,j,ans;
char b;
string c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(i=0;i<n;i++)
	  {cin>>a>>b;
	  for(j=0;j<a;j++)
		c+=b;}
	i=0;
	j=c.size()-1;
	while(i<j)
	  {if(c[i]!=c[j])ans++;
	  i++;
	  j--;}
	cout<<ans;
	return 0;
}