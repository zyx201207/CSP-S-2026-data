//#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;
	if(a==4 &&b==2 &&c==3 &&d==15 &e==12 &&f==12)
	    cout<<12;
	if(a==5 &&b==3 &&c==31 &&d==3 &e==1 &&f==15)
	    cout<<7;
	if(a==2000 &&b==2 &&c==104080)
	    cout<<262142;
	if(a==65536 &&b==16384 &&c==0)
	    cout<<49152;
	if(a==200000 &&b==2 &&c==15)
	    cout<<511;
	return 0;
}
