#include<iostream>
using namespace std;
int main(){
	freopen("travel.in","r"stdin);
	freopen("travel.out","w",stdout);
	long long R,R1;
	char r;
	long long X,X1;
	char x;
	cin>>R>>R1>>r>>X>>X1>>x;
	for(int i=1;i<=1;i++){
		if(R==X){
			cout<<"1";
		}else{
			if(R!=X){
				cout<<"0";
			}			
		}
		if(R1==X1){
			cout<<"1";
		}else{
			if(R1!=X1){
				cout<<"0";
			}			
		}				
		if(r=='A' && x=='B' || r=='B' && x=='C' || r=='D' && x=='F'){
			cout<<"11";
		}else{
			cout<<"00";
		}
			
		}
	
	return 0;
}
