#include<bits/stdc++.h>
using namespace std;
string cxa,cxb,zha,zhb;
int ans[5];
int ist(string a,string b){
	char x=a[2];
	char y=b[2];
	if((x=='A'&&y=='B')||(x=='A'&&y=='C')||(x=='B'&&y=='C')||(x=='B'&&y=='A')||(x=='C'&&y=='A')||(x=='C'&&y=='B')||(x=='D'&&y=='F')||(x=='F'&&y=='D'))return 1;
	else return 0;
}
int nb(string a,string b){
    char x=a[2];
    char y=b[2];
    if((x=='A'&&y=='C')||(x=='C'&&y=='A'))return 0;
    else return 1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cxa>>zha>>cxb>>zhb;
	int ma=0,mb=0,ia=0,ib=0;
	for(int i=0;i<2;i++){
		mb=mb*10+cxb[i]-'0';
		ma=ma*10+cxa[i]-'0';
	}
	for(int i=0;i<2;i++){
		ib=ib*10+zhb[i]-'0';
		ia=ia*10+zha[i]-'0';
	}
	ans[0]=ma==mb;
	if(ans[0]==0){
		cout<<"0000";
		return 0;
	}
	ans[1]=ia==ib;
	if(ans[1]==0){
		cout<<"1000";
		return 0;
	}
	ans[2]=ist(zha,zhb);
	if(ans[2]==0){
		cout<<"1100";
		return 0;
	}
	ans[3]=nb(zha,zhb);
	if(ans[3]==0){
		cout<<"1110";
	}else{
		cout<<"1111";
	}
	return 0;
} 
