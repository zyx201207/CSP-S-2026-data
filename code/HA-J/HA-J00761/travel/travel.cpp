#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2,a,b;
int c,d,x,y;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c1>>s1>>c2>>s2;
    a=a+s1[0]+s1[1];
    b=b+s2[0]+s2[1];
    x=s1[2],y=s2[2];
    c=c+a[0]-'0';
	c=c*10+a[1]-'0';
	d=d+b[0]-'0';
	d=d*10+b[1]-'0';
    bool f=true,f1=true;
	if((x==67 && y==68) || (x==68 && y==67)) f=false;
    if(c1==c2) cout<<"1";
    else{
    	cout<<"0000";
    	return 0;
    }
    if(a==b) cout<<"1";
    else{
    	f1=false;
    	cout<<"0";
    }
    if(!f1) cout<<"0";
    else if((x<=67 && y<=67) || (x>=68 && y>=68)) cout<<"1";
    else cout<<"0";
	if((abs(c-d)==1 && x==y && f) || (abs(x-y)==1 && c==d && f)) cout<<"1";
	else cout<<"0";
	 return 0;
}
