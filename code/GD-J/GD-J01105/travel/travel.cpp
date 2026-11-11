#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a,b,c,d,e,f,g,h,i,j;
	cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j;
	if(c==h&&d==i&&e==j)
	cout<<"0000";
	else {
	if(a==f&&b==g) cout<<"1";
		else cout<<"0";
	if(c==h&&d==i) cout<<"1";
		else cout<<"0";
	if(e=='F'||e=='D'){
		if(e=='F'&&j=='D'||e=='D'&&j=='F'||e=='D'&&j=='D'||e=='F'&&j=='F')
			cout<<"1";
	}
	else{
		if(e=='A'&&j=='A'||e=='A'&&j=='B'||e=='A'&&j=='C'||e=='B'&&j=='A'||e=='B'&&j=='B'||e=='B'&&j=='C'||e=='C'&&j=='A'||e=='C'&&j=='B'||e=='C'&&j=='C')
			cout<<"1";
			else cout<<"0";	
	}
	if(e=='C'&&j=='D')
	cout<<"0";
	else if(c!=1&&d!=0&&d!=9){
		if(e+1==j||e-1==j||e==j&&c==h&&d==i||d==i+1||d==i-1){
			cout<<"1";
			}
			else cout<<"0";
		}
	else if(e+1==j||e-1==j||e==j&&c==0&&d==9&&h==1&&i==0)
		cout<<"1";
		else cout<<"0";
	}
		return 0;
}
