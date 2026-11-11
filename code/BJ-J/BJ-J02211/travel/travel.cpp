#include<bits/stdc++.h>
using namespace std;
char a1,a2;
string s,k;
int main(){
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	cin>>a1>>s>>a2>>k;
	char l1[2],l2[2];
	for(int i=0;i<2;i++){
		l1[i]=s[i];
		l2[i]=k[i];
	}
	if(a1==a2){
		cout<<'1';
		if(l1==l2){
			cout<<'1';
			if(s[2]>'C'&&k[2]>'C'){
				cout<<"11";
			}else if(s[2]<='C'&&k[2]<='C'){
				cout<<'1';
				if(int(s[2])+1==int(k[2])||int(s[2])-1==int(k[2])){
					cout<<'1';
				}else cout<<'0';
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
