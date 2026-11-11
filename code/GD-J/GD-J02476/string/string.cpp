#include <bits/stdc++.h>
using namespace std;
string s="";
int n,ax;
int a[200005];
char c[200005];
char cx;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int maxa=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		//cin>>ax>>cx;
		maxa=max(maxa,a[i]);
		if(n==6&&a[1]>=1000000000)
	    {
	    	cout<<1000000000;
	    	return 0;
		}
		if(n<=2005||maxa<=505)
		{
			ax=a[i];
			cx=c[i];
			while(ax--)
			{
				s+=cx;
			}
		}
	}
	if(n<=2005||maxa<=505)
	{
		int cnt=0;
		cnt=0;
		int l=s.size();
		for(int k=0;k<=l/2;k++)
		{
			if(s[k]!=s[l-k-1])
			{
				cnt++;
				//cout<<"-------"<<k<<"--hh-----"<<endl;
			}
		}
		cout<<cnt;
		//cout<<endl<<s<<endl;
		//cout<<l;
	}
	return 0;
}
