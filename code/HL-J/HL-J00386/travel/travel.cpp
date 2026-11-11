#include<bits/stdc++.h>
using namespace std;
int a,b,f,z;
char c,e;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int u=0,m=0,k=0,l=0;
	cin>>a>>b>>c>>f>>z>>e;
	if(a==f)
	{
		u+=1;
	}
	if(b==z&&a==f)
	{
		m+=1;
	}
	if(((c=='F'&&e=='D')&&(a==f&&b==z))||(c=='D'&&e=='F'&&a==f&&b==z)||((c=='A'||c=='B'||c=='C')&&(a==f&&b==z))&&((e=='A'||e=='B'||e=='C')&&(a==f&&b==z)))
	{
		k+=1;
	}
	if((c=='F'&&e=='D'&&a==f&&b==z)||(c=='D'&&e=='F'&&a==f&&b==z)||(c=='B'&&e=='C'&&a==f&&b==z)||(c=='A'&&e=='B'&&a==f&&b==z)||(c=='C'&&e=='B'&&a==f&&b==z)||(c=='B'&&e=='A'&&a==f&&b==z))
	{
		l+=1;
	}
	cout<<u<<m<<k<<l;
	return 0;
}
