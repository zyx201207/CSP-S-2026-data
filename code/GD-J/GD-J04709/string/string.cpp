#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,a[N],xx,yy,sum,ans,s[N];
char c[N];
bool v[N];
string str;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	else if(1<n&&n<=2000)
	{
		for(int i=1;i<=n;i++)
	    {
		  cin>>a[i]>>c[i];
		  s[i]=s[i-1]+a[i];
		  int p=c[i]-'a'+1;
		  if(v[p]==false)
		    v[p]=true,sum++;
		  for(int j=1;j<=a[i];j++)
		    str+=c[i];
	    }
	    if(sum==1)
	    {
	    	cout<<0;
	    	return 0;
		}
		int z=0,y=str.size()-1;
		while(1)
		{
			if(z==y)
			  break;
			if(str[z]!=str[y])
			  ans++;
			z++,y--;
		}
		cout<<ans;
	}
	else
	{
		for(int i=1;i<=n;i++)
	    {
		  cin>>a[i]>>c[i];
		  s[i]=s[i-1]+a[i];
		  int p=c[i]-'a'+1;
		  if(v[p]==false)
		    v[p]=true,sum++;
	    }
	    if(sum==2)
	    {
	    	char p=c[1];
		    for(int i=1;i<=n;i++)
		    if(c[i]==p)
		      xx+=a[i];
		    else
		      yy+=a[i];
		    cout<<min(xx,yy);
		    return 0;
		}
	}
	return 0;
}
