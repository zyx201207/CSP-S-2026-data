#include<bits/stdc++.h>
using namespace std;
int a,b,ap,bp;
char ab,bb;
bool tongce(){
	if(ab>'C'&&bb>'C'){
		return 1;
	}else if(ab<='C'&&bb<='C'){
		return 1;
	}else{
		return 0;
	}
}
bool xianglin(){
	if(abs(int(ab-bb))==2)return 0;
	return 1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>ap>>ab;
	cin>>b>>bp>>bb;
	if(a==b){
		cout<<1;
		if(ap==bp){
			cout<<1;
			if(tongce()){
				cout<<1;
				if(xianglin()){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
