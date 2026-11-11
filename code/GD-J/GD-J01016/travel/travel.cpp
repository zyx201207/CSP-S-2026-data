#include<bits/stdc++.h> 
using namespace std;
string a[4];
	int b[4]={};
int pd(char x,char y){
	if((x==y&&(b[1]+1==b[3]||b[1]-1==b[3]))||(b[1]==b[3]&&(x+1==y||x-1==y))){
		if(x=='C'&&y=='D'||x=='D'&&y=='C'){
			return 0;
		}
		return 1;
	}else{
		return 0;
	}
}
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>a[0]>>a[1]>>a[2]>>a[3];
	for(int i=0;i<4;i++){
		if(i%2==0){
			for(int j=0;j<2;j++){
					if(j==0){
						b[i]+=(a[i][j]-'0')*10;
					}else{
						b[i]+=a[i][j]-'0';
					}
				}
			
		}else{
			for(int j=0;j<2;j++){
					if(j==0){
						b[i]+=(a[i][j]-'0')*10;
					}else{
						b[i]+=a[i][j]-'0';
					}
				}
			}
		
		
	}
	
	if(b[0]!=b[2]){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(b[1]==b[3]){
		cout<<"1";
		if(a[1][2]>'C'&&a[3][2]>'C'||a[1][2]<='C'&&a[3][2]<='C'){
			cout<<"1";
			if(pd(a[1][2],a[3][2])){
				cout<<"1";
			}else{
				cout<<"0";
			}
			return 0;
		}else{
			cout<<"0";
			if(pd(a[1][2],a[3][2])){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}
	}
	else{
		cout<<"00";
		if(pd(a[1][2],a[3][2])){
				cout<<"1";
			}else{
				cout<<"0";
			}
	}
	return 0;
}
