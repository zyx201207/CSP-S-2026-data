#include<bits/stdc++.h>
using namespace std;
char x,y;
bool f1,f2,f3,f4;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(abs(b[2]-d[2])==1)f4=1;
	else f4=0;
	if((b[0]==d[0]&&b[1]==d[1])&&((int(b[2])<=67&&int(d[2])<=67)||(int(b[2])>67&&int(d[2])>67)))f3=1;
	else {
		f3=0;f4=0;
	}
	if(b[0]==d[0]&&b[1]==d[1])f2=1;
	else {
		f2=0;f3=0;f4=0;
	}
	if(a[0]==c[0]&&a[1]==c[1])f1=1;
	else {
		f1=0;f2=0;f3=0;f4=0;
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
