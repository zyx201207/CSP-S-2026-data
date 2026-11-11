#include<bits/stdc++.h>
using namespace std;
using ll=long long; 
string c_1,s_1,c_2,s_2;
bool isoneside(string a,string b){
	char a_seat=a[2];
	char b_seat=b[2];
	if((a_seat>='A'&&a_seat<='C')&&(b_seat>='A'&&b_seat<='C')){
		return 1;
	}
	if((a_seat>='D'&&a_seat<='F')&&(b_seat>='D'&&b_seat<='F')){
		return 1;
	}
	return 0;
} 
int cti(char x){
	return x-'0';
}
bool isnext(string a,string b){
	char a_seat=a[2];
	char b_seat=b[2];
	if((a_seat=='D'&&b_seat=='F')||(a_seat=='F'&&b_seat=='D'))return 1;
	int val=a_seat-b_seat;
	return abs(val)==1; 
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c_1>>s_1>>c_2>>s_2;
	bool ans1=(c_1==c_2),ans2,ans3,ans4;
	if(ans1==0){
		cout<<"0000";
		return 0;
	}
	int row1=cti(s_1[0])+cti(s_1[1]);
	int row2=cti(s_2[0])+cti(s_2[1]);
	ans2=(row1==row2);
	if(ans2==0){
		cout<<"1000";
		return 0;
	}
	ans3=isoneside(s_1,s_2);
	if(ans3==0){
		cout<<"1100";
		return 0;
	}
	ans4=isnext(s_1,s_2);
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
} 
