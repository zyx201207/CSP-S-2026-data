//GZ-J00497 遵义市第八中学 龙长鑫 
#include<bits/stdc++.h>
using namespace std;
int x1,x2;
string z1,z2;
int wt4(){
	char a1=z1[2],a2=z2[2];
	int b1=(z1[0]-'0')*10+(z1[1]-'0');
	int b2=(z2[0]-'0')*10+(z2[1]-'0');
	if(b1==b2){
		if(a1+1==a2||a1-1==a2) cout<<"1";
		else cout<<"0";
	}else{
		if(a1==a2){
			if(b1+1==b2||b1-1==b2) cout<<"1";
			else cout<<"0";
		}else{
			cout<<"0";
		}
	}
}
int wt3(){
	if(z1[2]=='D'||z1[2]=='F'){
		if(z2[2]=='D'||z2[2]=='F'){
			cout<<"1";
			wt4();
		} 
		else cout<<"00";
	}else{
		if(z2[2]=='A'||z2[2]=='B'||z2[2]=='C'){
			cout<<"1";
			wt4();
		} 
		else cout<<"00";
	}
}
int wt2(){
	if(z1[0]==z2[0]&&z1[1]==z2[1]){
		cout<<"1";
		wt3();
	}  
	else{
		cout<<"00";
		wt4();
	} 
}
int wt1(){
	if(x1==x2){
		cout<<"1";
		wt2();
	}else{
		cout<<"0000";
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x1>>z1>>x2>>z2;
	wt1();
	return 0;
}


