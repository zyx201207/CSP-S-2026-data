#include<bits/stdc++.h>
using namespace std;
int c1,c2,a,b;
string s1,s2;
bool x,y,m,n;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a=(s1[0]-'0')*10+(s1[1]-'0');
	b=(s2[0]-'0')*10+(s2[1]-'0');
	if(c1==c2){
		x=1;
	}
	if(a==b&&x){
		y=1;
	}
	if(((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))&&y){
		m=1;
	}
	if(abs(s1[2]-s2[2])==1&&m){
		n=1;
	}
	cout<<x<<y<<m<<n;
	return 0;
}
