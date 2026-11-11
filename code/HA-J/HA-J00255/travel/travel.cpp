#include <bits/stdc++.h>
using namespace std;
long long ca,cb;
char sa[100005],sb[100005];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>cb>>sa>>sb;
	char a=sa[0],b=sb[0],c=sa[1],d=sb[1],e=sa[2],f=sb[2];	
	if(ca==cb){
		cout<<"1";
		if(a==b&&c==d){
			cout<<"1";
			if(e>='A'&&e<='C'&&e>='A'&&e<='C'){
				cout<<"1";
				if((e=='A'&&f=='B')||(e=='B'&&f=='A')||(e=='C'&&f=='B')||(e=='B'&&f=='C')){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else if((e=='D'&&f=='F')||(e=='F'&&f=='D')){
				cout<<"11";
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
