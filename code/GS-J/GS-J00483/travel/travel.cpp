#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,pai1,pai2;
	string s1,s2;
	char zuo1,zuo2;
	cin>>c1>>s1>>c2>>s2;
	pai1=(s1[0]-'0')*10+s1[1]-'0';
	pai2=(s2[0]-'0')*10+s2[1]-'0';
	zuo1=s1[2],zuo2=s2[2];
	if(c1==c2){
		cout<<1;
		if(pai1==pai2){
			cout<<1;
			if(zuo1=='A'||zuo1=='B'||zuo1=='C'&&zuo2=='A'||zuo2=='B'||zuo2=='C'){
				cout<<1;
				if(zuo1+1==zuo2||zuo1-1==zuo2){
					cout<<1;
				}else{
					cout<<0;
				}
			}
			else if(zuo1=='F'||zuo1=='D'&&zuo2=='D'||zuo2=='F'){
				cout<<1;
				if(zuo1+1==zuo2||zuo1-1==zuo2){
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
