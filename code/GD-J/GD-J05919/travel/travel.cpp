#include<bits/stdc++.h>
using namespace std;
char a[1000];
int main()
{
///freopen("travel.in","r",stdin);
///freopen("travel.out","w",stdout);
char w,s;
char c1,s1,c2,s2;
cin>>c1>>s1>>c2>>s2;
if(c1==c2)
	cout<<1;
else
	cout<<0;
for(int i=0;i<3;i++)
{
	if(a[i]>='A' && a[i]<='Z')
		w=a[i];
	else
		s=a[i];
}
if(s1==s2)
	cout<<0;	
else
	cout<<1;
if(w+1==char(68) || s-1==char(67))
	cout<<0;
else
	cout<<1;
if(w+1==char() || w-1==char(s))
	cout<<0;
else
	cout<<1;
//fclose(stdin);
//fclose(stdout);
return 0;
}
