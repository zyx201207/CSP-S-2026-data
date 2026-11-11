#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c_1,s_1,c_2,s_2;
	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1==c_2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c_1==c_2&&s_1.substr(0,2)==s_2.substr(0,2)){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c_1==c_2 && s_1.substr(0,2)==s_2.substr(0,2) && ((s_1[2]<='C'&&s_2[2]<='C') || (s_1[2]>='D'&&s_2[2]>='D'))){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c_1==c_2 && s_1.substr(0,2)==s_2.substr(0,2) && ((s_1[2]<='C'&&s_2[2]<='C') || (s_1[2]>='D'&&s_2[2]>='D'))){
		if(s_1[2]>='D'&&s_2[2]>='D'){
			if(s_1[2]-s_2[2]==2 || s_1[2]-s_2[2]==-2){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			if(s_1[2]-s_2[2]==1 || s_1[2]-s_2[2]==-1){
				cout<<1;
			}else{
				cout<<0;
			}
		}
	}else{
		cout<<0;
	}
	return 0;
}
