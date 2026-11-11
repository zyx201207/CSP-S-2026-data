#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int ra,rb,rc,xa,xb,xc;
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	ra=(a[0]-'0')*10+a[1]-'0';
	xa=(c[0]-'0')*10+c[1]-'0';
	rb=(b[0]-'0')*10+b[1]-'0';
	xb=(d[0]-'0')*10+d[1]-'0';
	rc=(c[2]<='C');
	xc=(d[2]<='C');
	cout<<(ra==xa)<<(ra==xa&&rb==xb)<<(ra==xa&&rb==xb&&rc==xc)<<(ra==xa&&rb==xb&&rc==xc&&abs(c[2]-d[2])==1)<<endl;
	return 0; 
} 
