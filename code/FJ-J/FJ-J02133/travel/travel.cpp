#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int sum1=0;
	int sum2=0;
	for(int i = 0;i < 2;i++){
		sum1+=c1[i];
		sum2+=c2[i];
	}
		if(sum1==sum2){
			cout<<"1";
			sum1=s1[0]+s1[1];
			sum2=s2[0]+s2[1];
			if(sum1==sum2){
				cout<<"1";
				char a=s1[2];
			char b=s2[2];
			if(a=='A'){
				if(b=='B'||b=='C'){
					cout<<"1";
				}else{
					cout<<"0";
				}
				if(b=='B'){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}
			
			if(a=='B'){
				if(b=='A'||b=='C'){
					cout<<"1";
				}else{
					cout<<"0";
				}
				if(b=='A'||b=='C'){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}
			if(a=='C'){
				if(b=='B'||b=='A'){
					cout<<"1";
				}else{
					cout<<"0";
				}
				if(b=='B'){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}
			if(a=='D'){
				if(b=='E'){
					cout<<"11";
				}else{
					cout<<"0";
				}
				
			}
			if(a=='E'){
				if(b=='D'){
					cout<<"11";
				}else{
					cout<<"0";
				}
			}
			}else{
				cout<<"000";
			}
	}else{
		cout<<"0000";
	}
	
	
	
	return 0;
}



