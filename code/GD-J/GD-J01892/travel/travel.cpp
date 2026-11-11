#include<bits/stdc++.h>
using namespace std;
int n,m,p,q;
char a1,a2,a3,b1,b2,b3;
bool x,y,z,w;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>a1>>a2>>a3>>m>>b1>>b2>>b3;
	p=(a1-'0')*10+(a2-'0'),q=(b1-'0')*10+(b2-'0');
	if(a3=='F') a3='E';
	if(b3=='F') b3='E';
	if(n==m) x=1;
	if(x&&p==q) y=1;
	if(y&&((a3<'D'&&b3<'D')||(a3>'C'&&b3>'C'))) z=1;
	if(z&&(a3-b3==1||b3-a3==1)) w=1;
	cout<<x<<y<<z<<w;
	
	
	return 0;
} 
