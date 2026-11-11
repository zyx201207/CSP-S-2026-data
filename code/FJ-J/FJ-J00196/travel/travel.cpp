#include <iostream>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,a1;
	string b,b1;
	cin>>a>>a1>>b>>b1;
	if(a==b){
		cout<<1;
								
		int s=0;
		for(int i=0;i<=1;i++){		
		if(a1[i]==b1[i]) s++;		
		}
		if(s==2){ cout<<1;
	
			if(a1[2]=='A'||a1[2]=='B'||a1[2]=='C'){
				if(b1[2]=='A'||b1[2]=='B'||b1[2]=='C'){ cout<<1;
					if(a1[2]-b1[2]==1||a1[2]-b1[2]==-1) cout<<1;
					else cout<<0;}
					}	
					else {cout<<"00";
				    return 0;}
		
			if(a1[2]=='D'||a1[2]=='F'){
				if(b1[2]=='D'||b1[2]=='F'){ cout<<1;
					if(a1[2]-b1[2]==1||a1[2]-b1[2]==-1) cout<<1;}
					else cout<<0;
				}
			
			
			else {cout<<"00";
			return 0;}
			
		}if(s!=2) {cout<<"000";
			return 0;}
		

	
	else{
		cout<<"0000";
		return 0;
	}
}
		
	return 0;}

