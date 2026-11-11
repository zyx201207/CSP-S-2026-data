#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string n,m;
	cin>>a>>n>>b>>m;
	char o=n[2],p=m[2];
	int q,l;
	if(n[0]=='0'){
		q=n[1]-'0';
	}
	if(n[0]=='1'){
		q=n[1]-'0'+10;
	}
	if(m[0]=='0'){
		l=m[1]-'0';
	}
	if(m[0]=='1'){
		l=m[1]-'0'+10;
	}
	if(a==b){
		cout<<'1'; 
		if(q==l){
			cout<<'1';
			if(((o=='A')||(o=='B')||(o=='C'))&&((p=='A')||(p=='B')||(p=='C'))){
				cout<<'1';
				if(((o=='A')&&(p=='C'))||((o=='C')&&(p=='A'))){
					cout<<'0';
					return 0;
				}
				else{
					cout<<'1';
				}
			}
			else if(((o=='D')&&(p=='F'))||((o=='F')&&(p=='D'))){
				cout<<"11";
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
