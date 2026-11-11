#include<bits/stdc++.h>
using namespace std;
#define ll long long
string c1,s1,c2,s2;
bool f1,f2,f3,f4;
bool check(char a,char b){
	return ((a=='A'&&b=='B')||(a=='B'&&b=='C')||(a=='D'&&b=='F'));
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) f1=1;
	int n1=(s1[0]-'0')*10+(s1[1]-'0');
	int n2=(s2[0]-'0')*10+(s2[1]-'0');
	if(f1&&(n1==n2)) f2=1;
	if(f2&&(s1[2]<'D'&&s2[2]<'D')||(s1[2]>='D'&&s2[2]>='D')) f3=1;
	if(f3&&(check(s1[2],s2[2])||check(s2[2],s1[2]))) f4=1;
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
