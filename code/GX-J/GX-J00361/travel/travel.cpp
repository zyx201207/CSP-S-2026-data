#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int a1,a2,a3,a4;
char a5;
int b1,b2,b3,b4;
char b5;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	a1=a[0]-'0';
	b1=c[0]-'0';
	a2=a[1]-'0';
	b2=c[1]-'0';
	a3=b[0]-'0';
	b3=d[0]-'0';
	a4=b[1]-'0';
	b4=d[1]-'0';
	if(a1==b1&&a2==b2) {
		cout<<1;
		if(a3==b3&&a4==b4){ 
		cout<<1;
			if((b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')||(b[2]>='D'&&b[2]<='E'&&d[2]>='D'&&d[2]<='E')){
				cout<<1;
				if((b[2]+1==d[2])||(b[2]-1==d[2])){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<0<<0<<endl;
			}
	}
	else{
		cout<<0<<0<<0<<endl;
	}
}
	else {
		cout<<0<<0<<0<<0<<endl;
	}
	
	return 0;
}
