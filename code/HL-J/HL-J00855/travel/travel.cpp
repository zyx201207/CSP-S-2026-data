#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	char e,f;
	int a,b,c,d;
	cin>>c1>>s1>>c2>>s2;
	a=s1[0]-'0';a*=10;
	b=s1[1]-'0';
//	cout<<" "<<a<<" "<<b;
    c=s2[0]-'0';c*=10;
	d=s2[1]-'0';
	e=s1[2];f=s2[2];
	if(c1==c2){
		cout<<1;
		if(a+b==c+d){
			cout<<1;
			if(((e=='A'||e=='B'||e=='C')&&(f=='A'||f=='B'||f=='C'))||((e=='D'||e=='E')&&(f=='D'||f=='E'))){
				cout<<1;
				if(((char)(e+1)==f||(char)(e-1)==f)&&!((e=='C'&&f!='D')||(e=='D'&&f!='C'))){
					cout<<1;
				}
				else{
					cout<<"0";
//					cout<<"e"<<e<<"f"<<f<<"e+1"<<(char)(e+1)<<"f+1"<<(char)(f+1)<<"e-1"<<(char)(e-1)<<"f-1"<<(char)(f-1);
				}
			}	
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	
	return 0;
}