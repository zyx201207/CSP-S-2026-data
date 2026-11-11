#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		int q=(s1[0]-'0')*10+s1[1]-'0';
		int w=(s2[0]-'0')*10+s2[1]-'0';
		if(w==q){
			cout<<"1";
			char e=s1[2];
			char w=s2[2];
			if(e=='A' && w=='C'){
				cout<<"10";
			}
			if(w=='A' && e=='C'){
				cout<<"10";
			}
			else if(e-w==1 || e-w==-1){
				cout<<"11";
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
	return 0;
}
