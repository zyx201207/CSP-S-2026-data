#include<bits/stdc++.h>
using namespace std;
string s11,s21,s22,s12;
int main(){
	freopen("treael.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s11>>s12>>s21>>s22;
	if(s11==s21){
		cout<<1;
		if(s12[0]==s22[0]&&s12[1]==s22[1]){
			cout<<1;
			if((s12[2]<'D'&&s22[2]<'D')||(s12[2]>='D'&&s22[2]>='D')){
				cout<<1;
				if(s12[2]=='D'&&s22[2]=='F'){
					cout<<1;
				}else if(s12[2]+1==s22[2]){
					cout<<1;
				}else if(s12[2]-1==s22[2]){
					cout<<1;
				}else if(s12[2]=='F'&&s22[2]=='D'){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<00;
			}
		}else{
			cout<<000;
		}
	}else{
		cout<<0000;
	}
	return 0;
}
// 
