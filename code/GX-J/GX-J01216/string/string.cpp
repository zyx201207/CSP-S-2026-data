#include<bits/stdc++.h>
using namespace std;

long long a[200000001];
int n,m,ans=0;
long long js=0,len=0;
char j;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	while(n--)
	{
		cin >> m >> j;
		for(int i=1;i<=m;i++)
		{
		    s[js+i]=j;
	    }
	    js+=m;
	}
	int flag=0;
	for(int i=1;i<=js;i++)
	  if(s[i]>='a' && s[i]<='z')  len++;
	for(int i=1;i<=len;i++)
	  if(s[i]!=s[len+1-i])
	    {
			a[len+1-i]=1;
			flag=1;
		}
	for(int i=1;i<=(len+1)/2;i++)
	  a[i]=0;
	if(flag==0)
	  cout << 0;
	else
	  for(int i=1;i<=len;i++)
	    if(a[i]==1)  ans++;
	if(flag!=0)
	  cout << ans;
    return 0;	
}
