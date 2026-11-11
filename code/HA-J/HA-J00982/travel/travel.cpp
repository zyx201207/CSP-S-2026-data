#include<bits/stdc++.h>
using namespace std;
string b,d;
int a,c,d1,b1,f=0;
char d2,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;		
	}
	else cout<<0;
	b1=(b[1]-'0')+((b[0]-'0')*10);
	d1=(d[1]-'0')+((d[0]-'0')*10);
	b2=b[2]-'A';
	d2=d[2]-'A';
	if(b1==d1&&a==c){
		cout<<1;
	}
	else cout<<0;
	if(b2<=2&&d2<=2&&a==c){
		if(b1==d1){
		cout<<1;
		f=1;
		}
	}
	else if(b2>=3&&d2>=3&&a==c){
		if(b1==d1){
		cout<<1;
		f=1;
		}
	}
	if(f==0) cout<<0;
	if(abs(b2-d2)<=1&&abs(b1-d1)<=1&&f==1&&a==c){
		cout<<1;
	}
	else cout<<0;
	return 0;
}
