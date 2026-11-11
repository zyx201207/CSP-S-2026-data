#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.ans","w",stdout);
	string c_1,c_2;
	string s_1,s_2;
	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1==c_2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	int num_1,num_2;
	int num_3;
	num_3=s_1[0]*1-48;
	num_1=num_3*10+s_1[1]*1-48;
	num_3=s_2[0]*1-48;
	num_2=num_3*10+s_2[1]*1-48;
	if(num_1==num_2){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(s_1[2]>'C'){
		if(s_2[2]>'C'){
			cout<<11;
		}else{
			cout<<"00";
		}
	}else{
		if(s_2[2]>'C'){
			cout<<"00";
		}else{
			cout<<1;
			int sum=max(s_1[2]*1,s_2[2]*1)-min(s_1[2]*1,s_2[2]*1);
			if(sum==1) cout<<1;
			else cout<<0;
		}
	}
	return 0;
}