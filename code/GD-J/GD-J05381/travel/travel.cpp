#include<bits/stdc++.h>
using namespace std;
string n1,s1,n2,s2;
string pai1,pai2;
char zuo1,zuo2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s1>>n1>>s2>>n2;
	if(s1==s2){
		cout<<1;
		pai1=n1[0]+n1[1];
		pai2=n2[0]+n2[1];
		if(pai1==pai2){
			cout<<1;
			zuo1=n1[2],zuo2=n2[2];
			if( ( (zuo1=='A'||zuo1=='B'||zuo1=='C') && (zuo2=='A'||zuo2=='B'||zuo2=='C') ) || ( (zuo1=='D'||zuo1=='F') && (zuo2=='D'||zuo2=='F') ) ){
				cout<<1;
				if(((zuo1=='A'||zuo1=='B')&&(zuo2=='A'||zuo2=='B'))||((zuo1=='C'||zuo1=='B')&&(zuo2=='C'||zuo2=='B'))||((zuo1=='D'||zuo1=='F')&&(zuo2=='D'||zuo2=='F'))){
					cout<<1<<"\n";
				}
				else cout<<0<<"\n";
			}
			else cout<<"00"<<"\n";
		}
		else cout<<"000"<<"\n";
	}
	else cout<<"0000"<<"\n";
	return 0;
} 
