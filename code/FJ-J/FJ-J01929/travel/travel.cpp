#include<bits/stdc++.h>
using namespace std;
int c1,c2,a,b;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	a=(s1[0]-48)*10+s1[1]-48;
	b=(s2[0]-48)*10+s2[1]-48;
	if(a==b){
		cout<<1;
		if(s1[2]<'D'&&s2[2]<'D'){
			cout<<1;
			if(int(s1[2]-s2[2])==1||int(s1[2]-s2[2])==-1){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
		else if(s1[2]>'C'&&s2[2]>'C'){
			cout<<"11";
		}
		else{
			cout<<"00";
		}
	}
	else{
		cout<<"000";
	}
	return 0;
}
