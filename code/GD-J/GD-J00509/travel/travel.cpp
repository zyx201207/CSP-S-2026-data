#include<bits/stdc++.h>
using namespace std;
#define ll long long
string c1,c2;
char s1,s2;
int n1,n2,side1,side2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>n1>>s1>>c2>>n2>>s2;
	if(c1==c2) cout<<1;
	else cout<<0;
	if(n1==n2&&c1==c2) cout<<1;
	else cout<<0;
	if(s1=='A'||s1=='B'||s1=='C') side1=1;
	if(s2=='A'||s2=='B'||s2=='C') side2=1;
	if(side1==side2&&c1==c2&&n1==n2) cout<<1;
	else cout<<0;
	if(abs((int)s1-(int)s2)==1&&side1==side2&&c1==c2&&n1==n2) cout<<1;
	else cout<<0;
	return 0;
}
