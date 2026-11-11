#include<bits/stdc++.h>
using namespace std;
int main(){
	string a,b,c,d;
	freopen("travel.in");
	freclose("travel.out");
	int l=0;
	int v=a[0]-'0';
	int n=c[0]-'0';
	v=v*10+a[1];
	n=n*10+c[1];
	if(v=n)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	int j=b[0]*10+b[1];
	int u=d[0]*10+d[1];
	if(j=u)
    {
    	cout<<1;
	}
	else
	{
		cout<<0;
	}
	int q=b[2]-'A',w=d[2]-'A';
	if(q/3==w/3)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		l=1;
	}
	if(l==1)
	{
		cout<<0;
	}
	else if(q-w==1||w-q==1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
