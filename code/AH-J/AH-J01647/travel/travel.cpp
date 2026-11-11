#include<bits/stdc++.h>
using namespace std;
int a1,b1;
string a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a>>b1>>b;
	if(a1==b1){
		cout<<1;
		string a2="",b2="";
		char a3=a[2],b3=b[2];
		a2=a[0]+a[1];
		b2=b[0]+b[1];
		if(a2==b2){
			cout<<1;
			if((a3<='C'&&b3<='C')||(a3>'C'&&b3>'C')){
				cout<<1;
				if((a3=='A'&&b3=='B')||(a3=='B'&&b3=='C')||(a3=='D'&&b3=='E')||(b3=='A'&&a3=='B')||(b3=='B'&&a3=='C')||(b3=='D'&&a3=='E')){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	return 0;
}
