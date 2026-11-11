#include<bits/stdc++.h>
using namespace std;
string s1[200005];
string s2[200005];
int main()
{  freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
    int n,sum=0,a,tot=0,flag=0;
    int ans;
    char b;
    int co=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a;
    	cin>>b;
    	for(int i=1;i<=a;i++)
    	{
    		tot++;
    		s1[tot]=b;
    		
		}
	}
	for(int i=tot;i>0;i--)
	{
		sum++;
		s2[sum]=s1[i];
		
	}
	for(int i=1;i<=tot;i++)
	{
		if(s1[i]!=s2[i])  flag++;
	}
	if(flag>1) ans=flag/2;
	else ans=0;
	cout<<ans;
return 0;
}

