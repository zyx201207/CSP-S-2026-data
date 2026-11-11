#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int s=0;
	int w=0;
	int F=0;
	int l=0;
	if(a==c){
		cout<<"1";
	}else {
		cout<<"0";
		w++;
	}
	if(w==0){
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<"1";
		}else cout<<"0";
	}else cout<<"0";
	if(w==0&&b[0]==d[0]&&b[1]==d[1]&&(b[2]=='A'&&d[2]=='B'||b[2]=='B'&&d[2]=='A'||b[2]=='C'&&d[2]=='B'||b[2]=='B'&&d[2]=='C'||b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D'||b[2]=='A'&&d[2]=='C'||b[2]=='C'&&d[2]=='A')){
		cout<<"1";
	}else{
		cout<<"0";
		F++;
	} 
	if(F==0){
	
		if(w==0&&b[2]=='A'&&d[2]=='B'){
			s++;
		
		}else if(w==0&&b[2]=='B'&&d[2]=='A'){
			s++;
		
		}else if(w==0&&b[2]=='C'&&d[2]=='B'){
			s++;
		
		}else if(w==0&&b[2]=='B'&&d[2]=='C'){
			s++;
		
		}else if(w==0&&b[2]=='D'&&d[2]=='F'){
			s++;
		
		}else if(w==0&&b[2]=='F'&&d[2]=='D'){
			s++;
	}
		}
	if(s==1){
		cout<<"1";
	}else cout<<"0";
	return 0;
}

