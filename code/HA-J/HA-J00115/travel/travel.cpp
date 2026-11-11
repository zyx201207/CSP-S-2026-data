#include<bits/stdc++.h>
using namespace std;
int main(){
char a=0,b=0,c=0,d=0;
cin>>a>>b>>c>>d;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	if(a=1)cout<<"0";
	else cout<<"1";
	if(a=16)cout<<"0";
	else cout<<"1";
	if(c=1)cout<<"0";
	else cout<<"1";
	if(c=16)cout<<"0";
	else cout<<"1";
	if(a!=c)cout<<"0";
	else cout<<"1";
     int e=printf("%1/b",b)+printf("%2/b",b);
     int f=printf("%1/b",d)+printf("%2/b",d);
    int g=printf("%3/b",b);
     int h=printf("%3/b",d);
	if(e=f)cout<<"1";
	else cout<<"0";
	if(g=h+1)cout<<"1";
	else cout<<"0";
	return 0;
}
