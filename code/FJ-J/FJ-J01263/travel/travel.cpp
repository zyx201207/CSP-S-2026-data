#include<bits/stdc++.h>
using namespace std;
string a,b;
int a1,b1,q=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","r",stdout);
	cin>>a1>>a>>b1>>b;
	if(a1==b1) cout<<"1";
	else cout<<"0";
	if(a[1]==b[1]&&a[2]==b[2]) cout<<"1";
	else cout<<"0";
	if(a[3]<='C'&&a[3]>='A'&&b[3]<='C'&&b[3]>='A') 
	{
		cout<<"1";
		if(a[3]-1==b[3]||a[3]==b[3]-1) cout<<"1";
	}
	else
	{
		if(a[3]<='F'&&a[3]>='D'&&b[3]<='F'&&b[3]>='D')
		{
		cout<<"1";	
		if(a[3]-1==b[3]||a[3]==b[3]-1) cout<<"1";
		}
        else cout<<"0";
	}
	return 0;
}
