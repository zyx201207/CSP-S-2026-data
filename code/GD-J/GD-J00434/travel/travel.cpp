#include<bits/stdc++.h>
using namespace std;
string s1,s2;
char c1,c2,c3,c4,c5,c6;
int a1,a2,a3,a4,ic3,ic6;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s1>>c1>>c2>>c3>>s2>>c4>>c5>>c6;
	if(s1==s2)  a1=1;
	else  a1=0;
	if(c1==c4&&c2==c5&&a1==1)  a2=1;
	else  a2=0;
	if((a2==1)&&(((c3=='A'||c3=='B'||c3=='C')&&(c6=='A'||c6=='B'||c6=='C'))||((c3=='D'||c3=='F')&&(c6=='D'||c6=='F'))))  a3=1;
	else  a3=0;
	ic3=c3-'0';
	ic6=c6-'0';
	if((a3==1)&&abs(ic3-ic6)==1)  a4=1;
	else  a4=0;
	cout<<a1<<a2<<a3<<a4;
	return 0;
}
