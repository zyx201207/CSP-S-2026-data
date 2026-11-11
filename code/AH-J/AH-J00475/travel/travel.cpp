#include<bits/stdc++.h>
using namespace std;
struct node{
	string c,s;
};
node a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a.c>>a.s>>b.c>>b.s;
	///cout<<a.c<<a.s<<b.c<<b.s;
	if(a.c==b.c){
		cout<<"1";
		if(a.s[0]==b.s[0]&&a.s[1]==b.s[1]){
			cout<<"1";
			if(a.s[2]>='A'&&a.s[2]<='C'&&b.s[2]>='A'&&b.s[2]<='C'){
				cout<<"1";
				if(a.s[2]-b.s[2]==1||b.s[2]-a.s[2]==1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else if(a.s[2]<='F'&&a.s[2]>='D'&&b.s[2]<='F'&&a.s[2]>='D'){
				cout<<"11";
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}



	return 0;
}
