//GZ-J100010 六盘水市第四实验中学 彭荣锦 
#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	int a1=0,a3=0;
	bool q=false;
	a1+=(s1[0]-'0')*10+(s1[1]-'0');
	a3+=(s3[0]-'0')*10+(s3[1]-'0');
	if(a1==a3){
		cout<<1;
		q=true;
	}
	else cout<<0;
	int a2=0,a4=0;
	bool b=false;
	a2+=(s2[0]-'0')*10+(s2[1]-'0');
	a4+=(s4[0]-'0')*10+(s4[1]-'0');
	if(a2==a4 && q){
		cout<<1;
		b=true;
	}
	else cout<<0;
	int x2,x4;
	bool c=false;
	x2=s2[2]-'A'+1;
	x4=s4[2]-'A'+1;
	if(b){
		if((x2<=3 && x4<=3)||(x2>3 && x4>3)){
			cout<<1;
			c=true;
		}
		else cout<<0;
	}
	else cout<<0;
	if(c){
		if(x2<=3 && x4<=3){
			if(abs(x2-x4)==1) cout<<1;
			else cout<<0;
		}
		else cout<<1;
	}
	else cout<<0;
	return 0;
}
