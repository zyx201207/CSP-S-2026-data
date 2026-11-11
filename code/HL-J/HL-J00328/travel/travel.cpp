#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000"<<endl;
		return 0;
	}else cout<<1;
	string k1,k2;
	for(int i=0;i<2;i++){
		k1+=s1[i];
		k2+=s2[i];
	}if(k1!=k2){
		cout<<"000";
		return 0;
	}else cout<<1;
	char x=s1[2];
	char y=s2[2];
	if(x>='A'&&x<='C'&&y>='A'&&y<='C'){
		cout<<1;
		if(x=='A'&&y=='B'){
			cout<<1;
		}else if(x=='B'&&y=='A'){
			cout<<1;
		}else if(x=='B'&&y=='C'){
			cout<<1;
		}else if(x=='C'&&y=='B'){
			cout<<1;
		}else{
			cout<<0;
			return 0;
		}
	}else if(x>='D'&&x<='F'&&y>='D'&&y<='F'){
		cout<<"11";
	}else{
		cout<<"00";
	}
	return 0;
}