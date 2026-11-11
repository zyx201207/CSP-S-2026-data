#include<bits/stdc++.h>
using namespace std;
int main(){
		freopen('travel.in'.r.stdin);
	freopen('travel.out'.w.stdout);
int a,c;
string b,d;
cin>>a>>b>>c>>d;
int n=b[2];
	
int m=d[2];
	


	
if(a==c){
	cout<<"1";
	if(b[0]==d[0] and b[1]==d[1]){
		cout<<"1";
		if(n+m==138){
			cout<<"11";
		}
		else{
			if(n+m==131){
				cout<<"11";
			}
			else{
				if(n==67 and m==66){
					cout<<"11";
				}
				else{
					if(n==66 and m==67){
						cout<<"11";
					}
					else{
						if(n==65 and m==67){
							cout<<"01";
						}
						else{
							cout<<"00";
						}
					}
				}
					
				}
			}
		}
	
	
		
else{
		cout<<"000";
	}

}
else{
	cout<<"0000";
}
	
	
	
	
	
	
	


	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
