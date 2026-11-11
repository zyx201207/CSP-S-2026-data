#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string a1=s1.substr(0,2),a2=s2.substr(0,2);
	char b1=s1[2],b2=s2[2];
	if(b1>b2) swap(b1,b2);
	if(c1==c2){
		cout<<1;
		if(a1==a2){
			cout<<1;
			if(b1>='D'){
				cout<<1;
				if(b1=='D'&&b2=='F') cout<<1;
				else cout<<0;
			}
			else if(b2<='C'){
				cout<<1;
				if(b1=='A'&&b2=='B') cout<<1;
				else if(b1=='B'&&b2=='C') cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000"; 
	return 0;
}
