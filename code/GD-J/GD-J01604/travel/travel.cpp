#include<bits/stdc++.h>
using namespace std;

int main(){
	
	
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string as={},an={},bn={},bs={};
	int a=0,b=0,ad=0,bd=0;
	cin>>a>>as>>b>>bs;
	
	ad=as[0]*10+as[1];
	bd=bs[0]*10+bs[1];
	
	if(a==b){
		if(ad==bd){
			if(as[2]='F'&&bs[2]=='D'||as[2]=='D'&&bs[2]=='F'){
				cout<<"1111";
			}else{
				if(as[2]='C'&&bs[2]=='D'||as[2]=='D'&&bs[2]=='C'){
				    cout<<"1100";
				}else{
					if(as[2]-bs[2]>=-1&&as[2]-bs[2]<=1) cout<<"1111";
					else cout<<"1100";
				}
			}
			
			
		}else{
			cout<<"1000";
		}
		
		
	}else{
		cout<<"0000";
	}
	
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

 
