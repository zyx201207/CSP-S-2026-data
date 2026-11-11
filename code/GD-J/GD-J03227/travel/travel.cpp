#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<'1';
	}else{
		cout<<'0';
	}
	int p1,p2;
	p1=(s1[0]-'0')*10+s1[1]-'0';
	p2=(s2[0]-'0')*10+s2[1]-'0';
	if(p1==p2&&c1==c2){
		cout<<'1';
	}else{
		cout<<'0';
	}
	int z1,z2;
	if(s1[2]=='D'||s1[2]=='F'){
		z1=0;
	}else{
		z1=1;
	}
	if(s2[2]=='D'||s2[2]=='F'){
		z2=0;
	}else{
		z2=1;
	}
	if(z1==z2&&p1==p2&&c1==c2){
		cout<<'1';
	}else{
		cout<<'0';
	}
	char w1=s1[2];
	char w2=s2[2];
	if(c1==c2&&p1==p2&&z1==z2){
		if(z1==0&&w1!=w2){
			cout<<'1';
			return 0;
		}
		else if(w1=='A'&&w2=='B'){
			cout<<'1';
		}
		else if(w1=='B'&&w2=='A'){
			cout<<'1';
		}
		else if(w1=='C'&&w2=='B'){
			cout<<'1';
		}
		else if(w1=='B'&&w2=='C'){
			cout<<'1';
		}else{
			cout<<'0';
		}
	}else{
		cout<<'0';
	}
	return 0;
} 
