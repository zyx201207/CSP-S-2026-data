#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,x,y;
	cin>>a>>b>>x>>y;
	if(a==x){
		
	}else{
		cout<<"0000";
		return 0;
	}
	if(b[0]==y[0]&&b[1]==y[1]){
		
	}else {
		cout<<"1000";
		return 0;
	}
	if((b[2]<='C'&&y[2]<='C')||(b[2]>'C'&&y[2]>'C')){
		
	}else{
		cout<<"1100";
		return 0;
	}
	
	char zm[5]={'A','B','C','D','F'};
	int n,m;
	for(int i=0;i<5;i++){
		if(b[2]==zm[i]){
			n=i+1;
		}
		if(y[2]==zm[i]){
			m=i+1;
		}
	}
	int cha=n-m;
	if(abs(cha)==1){
		
	}else {
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
