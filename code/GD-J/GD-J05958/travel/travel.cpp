#include<iostream>
using namespace std;
int main(){
freopen("travel.in","r",stdin)
freopen("travel.out","w",stdout)
	int a,c;string b,d;
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
		return 0;
	}else if(a==c){
		cout<<"1";
		if(b[0]!=d[0]||b[1]!=d[1]){
			cout<<"000";
			return 0;
		}else if(b[0]==d[0]&&b[1]==d[1]){
			cout<<"1";
			if(72<=b[2]+1&&b[2]+1<=74||d[2]+1>=75&&d[2]+1<=76){
				cout<<"00"; 
				return 0;
			}
			if(72<=d[2]+1&&d[2]+1<=74||b[2]+1>=75&&b[2]+1<=76){
				cout<<"00";
				return 0;
			}
			if(d[2]+1==75&&b[2]+1==74||b[2]+1==75&&d[2]+1==74){
				cout<<"00";
				return 0;
			} 
			if(b[2],d[2]=='A'||'B'||'C'){
				cout<<"1";
			}else if(b[2],d[2]=='D'||'F'){ 
			 cout<<"1";
			}
			if(b[2]==d[2]+1||d[2]==b[2]+1){
				cout<<"1";
				return 0;
			}else{
				cout<<"0";
				return 0;
			}
		}		
	}
}
