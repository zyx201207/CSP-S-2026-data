#include<bits/stdc++.h>
using namespace std;
int a,c;
string b,d;
int main(){
	freopen("r","travel.in",stdin);
	freopen("w","travel.out",stdout);
	cin>>a>>b>>c>>d;
	bool a1,a2,a3,a4;
	a1= (a==c) ;
	a2= a1&&(b[0]==d[0]&&b[1]==d[1]);
	a3= a2&&((b[2]=='D'&&d[2]=='F')||
	(d[2]=='D'&&b[2]=='F')||
	(b[2]=='A'&&d[2]=='B')||
	(d[2]=='A'&&b[2]=='B')||
	(b[2]=='A'&&d[2]=='C')||
	(d[2]=='A'&&b[2]=='C')||
	(b[2]=='B'&&d[2]=='C')||
	(d[2]=='B'&&b[2]=='C')
	);
	a4= a3&(abs(b[2]-d[2])==1);
	cout<<a1<<a2<<a3<<a4;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
