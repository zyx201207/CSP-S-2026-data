//李昊阳 个人报名 GZ-J00639
#include <bits/stdc++.h> 
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else {
		cout<<0;
	}
	string a,b;
	a=s1[0]+s1[1];
	b=s2[0]+s2[1];
	if(a==b){
		cout<<1;
	}
	else{
		cout<<0;
	}
	char q=s1[2]-'A';
	char w=s2[2]-'A';
	
	if((q<=2&&w<=2)||(q>=3&&w>=3)){
		cout<<1;
		if(q>=3&&w>=3){
			cout<<1;
		}
		else if(q-w==1||w-q==1){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<0;
		cout<<0;
	}
	return 0;
}
