#include<bits/stdc++.h>
using namespace std;
const int N=11;
string c1,c2,s1,s2;
int a,b,c,d,n,m,len1,len2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c1>>s1>>c2>>s2;
	a=1,b=1,c=1,d=1;
	if(c1!=c2)
	  a=b=c=d=0;
	cout<<a;
	for(int i=0;i<max(s1.size(),s2.size());i++)
	  if(s1[i]!=s2[i]&&s1[i]>='0'&&s1[i]<='9'&&s2[i]>='0'&&s2[i]<='9')
	    b=0;
	if(b==0)
	  c=d=0;
	cout<<b;
	n=s1.size()-1,m=s2.size()-1;
	if(s1[n]>='A'&&s1[n]<='C'&&c==1)
	{
		if(s2[m]>='A'&&s2[m]<='C'&&c==1)
		  c=1;
		else
		  c=0;
	}
	else if(s1[n]>='D'&&s1[n]<='F'&&s1[n]!='E'&&c==1)
	{
		if(s2[m]>='D'&&s2[m]<='F'&&s2[m]!='E'&&s1[n]!=s2[m]&&c==1)
		  c=1;
		else
		  c=0;
	}
	if(c==0)
	  c=d=0;
    cout<<c;
    if(abs(s1[n]-s2[m])!=1)
      d=0;
    cout<<d;
	return 0;
}
