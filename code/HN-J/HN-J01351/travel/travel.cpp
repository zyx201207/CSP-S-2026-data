#include<bits/stdc++.h>
using namespace std;
int main(){ 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a[10];
	string q,w;
		cin>>a[0]>>q>>a[1]>>w; 
		if(a[0]==a[1]){
			cout<<"1";
			if(q[0]==w[0]&&q[1]==w[1]){
				cout<<"1"; 
				if(q[2]+1!=w[2]||q[2]-1!=w[2]&&q[2]!='D'&&w[2]!='C'&&q[2]!='C'&&w[2]!='D'){
					cout<<"1";
					if(q[2]=='A'&&w[2]=='B'){
						cout<<"1";
					}else if(q[2]=='B'&&w[2]=='C'){
								cout<<"1";		
					}else if(q[2]=='D'&&w[2]=='F'){
								cout<<"1";	
					}else if(q[2]=='C'&&w[2]=='B'){
								cout<<"1";		
					}else if(q[2]=='F'&&w[2]=='D'){
								cout<<"1";	
					}else if(q[2]=='B'&&w[2]=='A'){
								cout<<"1";	
					}else{
						cout<<"0";
					}	
				}else{
					cout<<"00";
				}
			}else{
				cout<<"000";	
			}
		}else{
			cout<<"0000";
		}
	return 0;
}
