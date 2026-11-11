#include<bits/stdc++.h>
using namespace std;
int main(){
	fopen("travel.in","r",stdin);
	fopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string pos1,pos2,pos3,pos4;
	cin>>pos1>>pos2>>pos3>>pos4;
	bool s=0,s1=0,s2=0;
	if(pos1 == pos3){
		cout<<1;
		s = 1;
	}else cout<<0;
	int A = stoi(pos2);
	int B = stoi(pos4);
	if(A == B && s==1){
		cout<<1;
		s1 = 1;
	}else cout<<0;
	if(((pos2[2] <='C' && pos4[2] <='C') ||  (pos2[2]>='D' && pos4[2]>='D'))  && s1 == 1){ 
		cout<<1;
		s2 = 1;
	}
	else cout<<0;
	if((s2==1) && (abs(pos2[2]-pos4[2]) == 1) &&(pos2[2]+pos4[2]!=135)){
		cout<<1;
		return 0;
	}
	cout<<0;
	return 0;
} 
