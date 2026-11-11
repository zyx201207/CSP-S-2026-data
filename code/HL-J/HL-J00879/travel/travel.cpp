#include<bits/stdc++.h>;
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,b11,b12,b13,a2,b21,b22,b23;
	cin>>a1>>b11>>b12>>b13>>a2>>b21>>b22>>b23;
	if(a1==a2&&a1!='1'&&a1!='16'&&a2!='1'&&a2!='16') cout<<"1";
	else if cout<<"0";
	if(b11==b21&&b12==b22&&b12!='1'&&b12!='16'&&b22!='1'&&b22!='16') cout<<"1";
	else if cout<<"0";
	while(b11==b21&&b12==b22&&b12!='1'&&b12!='16'&&b22!='1'&&b22!='16'){
        if(b13=='A'&&b23=='B'||b23=='C')cout<<"1";
        else if(b13=='B'&&b23=='A'||b23=='C')cout<<"1";
        else if(b13=='C'&&b23=='B'||b23=='A')cout<<"1";
        else if(b13=='E'&&b23=='F')cout<<"1";
        else if(b13=='F'&&b23=='E')cout<<"1";
        else if cout<<"0";
	}
	if(b13-=b23||b13+=b23) cout<<"1";
	else if cout<<"0";
	return 0;
}
