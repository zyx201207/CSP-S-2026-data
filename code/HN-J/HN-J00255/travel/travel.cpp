#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<'1';
		else cout<<'0';
	int a1=(s1[0]-'0')*10+s1[1]-'0';
	int a2=(s2[0]-'0')*10+s2[1]-'0';
	if(c1==c2&&a1==a2) cout<<'1';
		else cout<<'0';
	int b1=s1[2]-'A';
	int b2=s2[2]-'A';
	if(c1==c2&&a1==a2&&((b1<3&&b2<3)||(b1>2&&b2>2))) cout<<'1';	
		else cout<<'0';
	if(c1==c2&&a1==a2&&((b1<3&&b2<3)||(b1>2&&b2>2))&&abs(b1-b2)==1) cout<<'1';
	else cout<<'0';
	return 0;
} 
