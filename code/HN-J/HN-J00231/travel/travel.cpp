#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+10;
ll n,m,num,a[N];
string c1,s1,c2,s2;
char n1,m1;
int tl(char s){
	if(s>='A'&&s<='C')return 1;
	if(s>='D'&&s<='F')return 2;
}
int main(){
	freopen(" travel.in","r",stdin);
	freopen(" travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	n=s1[0]-'0'+s1[1]-'0';
	m=s2[0]-'0'+s2[1]-'0';
	n1=s1[2];
	m1=s2[2];
	if(c1==c2)cout<<1;
	else cout<<0;
	if(c1==c2&&n==m)cout<<1;
	else cout<<0;
	if(c1==c2&&n==m&&tl(n1)==tl(m1))cout<<1;
	else cout<<0;
	if(c1==c2&&n==m&&tl(n1)==tl(m1)&&abs(int(n1-m1))==1)cout<<1;
	else cout<<0;
	return 0;
}
