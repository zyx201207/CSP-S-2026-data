#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int sum,num;
struct E{
	int p,s;
}man,manba;
int f(char bd){
	if(bd=='A'){
		return 1;
	}
	if(bd=='B'){
		return 2;
	}
	if(bd=='C'){
		return 3;
	}
	if(bd=='D'){
		return 4;
	}
	if(bd=='F'){
		return 5;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	for(int i=0;i<2;i++){
		int x=a[i]-'0',y=c[i]-'0';
		sum+=x*pow(10,1-i);
		num+=y*pow(10,1-i);
	}
	if(sum!=num){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	for(int i=0;i<2;i++){
		int x=b[i]-'0',y=d[i]-'0';
		man.p+=x*pow(10,1-i);
		manba.p+=y*pow(10,1-i);
	}
	man.s=f(b[2]);
	manba.s=f(d[2]);
	if(man.p==manba.p){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((man.s<=3&&manba.s<=3)||(man.s>=4&&manba.s>=4)){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(man.s-manba.s)==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
