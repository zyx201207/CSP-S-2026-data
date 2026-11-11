#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	int s1=c1.size();
	int s2=c2.size();
	int s3=c3.size();
	int s4=c4.size();
	if(s1!=s3){
		cout<<"0000";
		return 0;
	}
	bool b1=1,b2=2,b3=3,b4=4;
	for(int i=0;i<s1;i++){
		if(c1[i]!=c3[i]){
			b1=0;
			cout<<"0000";
			return 0;
		}
	}
	if(b1){
		cout<<'1';
	}
	if(s2!=s4){
		cout<<"000";
		return 0;
	}
	for(int i=0;i<s2-1;i++){
		if(c2[i]!=c4[i]){
			b2=0;
			cout<<"000";
			return 0;
		}
	}
	if(b2){
		cout<<'1';
	}
	char z1,z2;
	z1=c2[s2-1];
	z2=c4[s4-1];
	if(('A'<=z1&&z1<='C'&&'A'<=z2&&z2<='C')||(('D'==z1&&z1=='F')&&('D'==z2||'F'==z2))){
		cout<<'1';
	}else{
		cout<<"00";
		return 0;
	}
	char z3=z1+1;
	char z4=z1-1;
	if(z3==z2||z4==z2){
		cout<<'1';
	}else{
		cout<<'0';
	}
	return 0;
}
