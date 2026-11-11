#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("travel.in","r",stdin);//记得开！！！！！！！！！！ 
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s1,s2,c1,c2;
	cin>>c1>>s1>>c2>>s2;
	char zu1=s1[2],zu2=s2[2];
	if (c1==c2){
		cout<<1;
		if (s1[0]==s2[0]&&s1[1]==s2[1]){//同一排 
			cout<<1;
			if ((zu1>='A'&&zu2>='A'&&zu1<='C'&&zu2<='C')||(zu1=='D'&&zu2=='F')||(zu2=='D'&&zu1=='F')){
				cout<<1;
				if (zu1>='A'&&zu2>='A'&&zu1<='C'&&zu2<='C'){
					if (abs(int(zu1-zu2))==1){
						cout<<1;
					}
					else{
						cout<<0;
					}
				}
				else if ((zu1=='D'&&zu2=='F')||(zu2=='D'&&zu1=='F')){
					cout<<1;
				}
				else{
					cout<<0;
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
} 
