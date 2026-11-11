#include<bits/stdc++.h>
using namespace std;
string w1,w2;
int c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>w1>>c2>>w2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000"; 
		return 0;
	}
	if(w1[0]+w1[1]==w2[0]+w2[1]&&c1==c2){
		 cout<<1;
	}else{
		cout<<"000";
		return 0;
	}if(w1[2]=='A'||w1[2]=='B'||w1[2]=='C'&&w1[0]+w1[1]==w2[0]+w2[1]&&c1==c2){
		if(w2[2]=='A'||w2[2]=='B'||w2[2]=='C'){
			cout<<1;
		}else{
			cout<<"00";
			return 0;
		}
	}else if(w1[2]=='D'||w1[2]=='E'&&w1[0]+w1[1]==w2[0]+w2[1]&&c1==c2){
		if(w2[2]=='D'||w2[2]=='E'){
			cout<<1;
		}else{
			cout<<"00";
			return 0;
		}
	}else{
		cout<<"00";
		return 0;
	}
	if(w1[2]=='A'&&w1[0]+w1[1]==w2[0]+w2[1]&&c1==c2){
		if(w2[2]=='B'){
			cout<<1;
		}else cout<<0;
	}else if(w1[2]=='B'&&w1[0]+w1[1]==w2[0]+w2[1]&&c1==c2){
		if(w2[2]=='A'||w2[2]=='C'){
			cout<<1;
		}else cout<<0;
	}else if(w1[2]=='C'&&w1[0]+w1[1]==w2[0]+w2[1]&&c1==c2){
		if(w2[2]=='B'){
			cout<<1;
		}else cout<<0;
	}else if(w1[2]=='D'&&w1[0]+w1[1]==w2[0]+w2[1]&&c1==c2){
		if(w2[2]=='E'){
			cout<<1;
		}else cout<<0;
	}else if(w1[2]=='E'&&w1[0]+w1[1]==w2[0]+w2[1]&&c1==c2){
		if(w2[2]=='D'){
			cout<<1;
		}else cout<<0;
	}else{
		cout<<0;
	}
	
}
