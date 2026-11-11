#include<bits/stdc++.h>
using namespace std;

string a2,b2;
int a1,b1;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(a2[0]==b2[0]&&a2[1]==b2[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	int ax=a2[2]-' ';//A33 B34 C35     D36 (E37) F38
	int bx=b2[2]-' ';
	if(ax>35&&bx>35){
		cout<<11;
	}else if(ax<=35&&bx<=35){
		if((ax==33&&bx==35)||(ax==35&&bx==33)){
			cout<<"10";
		}else{
			cout<<"11";
		}
	}else{
		cout<<"00";
	}
	

    return 0;
}
