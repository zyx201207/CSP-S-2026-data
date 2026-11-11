#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}
	else cout<<"0";
	int strlen(s1),strlen(s2);
	for(int i=1;i<strlen(s1);i++){
		for(int j=1;j<strlen(s2);j++){
			if(s1[i]==s2[i]){
				cout<<"1";
			}
			else cout<<"0";
		}
	}
	if(a=A,b=B&a=B,b=A&&a=C,b=D&&a=D,b=C&&a=D,b=E&&a=F,b=D)cout<<"1";
	else cout<<"0";
	int a=s1[strlen(s1)],b=s2[strlen(s2)];
	if(a=B,b=C&&a-b!=1)cout<<"0";
	else cout<<"1";
}