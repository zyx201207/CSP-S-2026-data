#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,e,f;
bool r,t;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    cout<<(bool)(a==c);
    e=b[0]+b[1];
    f=d[0]+d[1];
    t=(bool)(e==f&&a==c);
    cout<<(bool)(e==f&&a==c);
    e=b[2];
	f=d[2];
	if(t)
	{
		if(e=="A"&&(f=="B"||f=="C")) r=1;
		if(e=="B"&&(f=="C"||f=="A")) r=1;
		if(e=="C"&&(f=="B"||f=="A")) r=1;
		if(e=="E"&&(f=="F")) r=1;
		if(e=="F"&&(f=="E")) r=1;
	}
	cout<<r;
	r=0;
	if(t)
	{
		if(e=="A"&&(f=="B")) r=1;
		if(e=="B"&&(f=="C"||f=="A")) r=1;
		if(e=="C"&&(f=="B")) r=1;
		if(e=="E"&&(f=="F")) r=1;
		if(e=="F"&&(f=="E")) r=1;
	}
	cout<<r;
    return 0;
}

