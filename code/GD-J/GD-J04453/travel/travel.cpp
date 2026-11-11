#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>s1>>s2>>c1>>c2;
	if(s1==c1){
		cout<<1;
		if(s2[0]==c2[0]&&s2[1]==c2[1]){
			cout<<1;
			if(s2[2]<='C'&&c2[2]<='C'){
				cout<<1;
				if(s2[2]-c2[2]<=1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else if(s2[2]>'C'&&c2[2]>'C'){
				cout<<1;
				cout<<1;
			}else{
				cout<<0;
				cout<<0;
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}
	
	return 0;
} 
