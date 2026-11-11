#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	bool q1=0,q2=0,q3=0,q4=0;
	for(int i=0;i<c1.size();i++){
		if(c1[i]!=c3[i]) q1=true; 
	}
	int l1=c1.size();
	int l2=c3.size();
	if(l1!=l2) q1=true;
	if(q1){
		cout<<"0000";
		return 0;
	}
	int l3=c2.size();
	int l4=c4.size();
	if(l3!=l4) q2=true;
	for(int i=0;i<l3-1;i++){
		if(c2[i]!=c4[i]) q2=true;
	}
	if(q2){
		cout<<"1000";
		return 0;
	}
	if((c2[l3-1]<='C'&&c4[l3-1]<='C'&&c2[l3-1]>='A'&&c4[l3-1]>='A')||(c2[l3-1]>='D'&&c4[l3-1]>='D'&&c2[l3-1]<='F'&&c4[l3-1]<='F')){
		q3=1;
	}
	if(!q3){
		cout<<"1100";
		return 0;
	}
	if((c2[l3-1]=='A'&&c4[l3-1]=='B')||(c2[l3-1]=='B'&&c4[l3-1]=='C')||(c2[l3-1]=='D'&&c4[l3-1]=='F')){
		q4=1;
	}
	if((c4[l3-1]=='A'&&c2[l3-1]=='B')||(c4[l3-1]=='B'&&c2[l3-1]=='C')||(c4[l3-1]=='D'&&c2[l3-1]=='F')){
		q4=1;
	}
	if(!q4){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}