#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c[10],s[10];
	cin>>c[1]>>s[1]>>c[2]>>s[2];
	
	if( c[1] == c[2] ){
		
		cout<<"1";
		
		if( ( s[1][0] + s[1][1] ) == ( s[2][0] + s[2][1] ) ) {
			
			cout<<"1";
			
			if( s[1][2] <= 'C' && s[1][2] >='A' ) {
				
				if( s[2][2] <= 'C' && s[2][2] >='A' ){
					
					cout<<"1";
					
					if(  s[1][2] != 'B' && s[2][2] != 'B' ){
						
						cout<<"0";
						
					}else{
						
						cout<<"1";
						
					}
					
				}else{
					
					cout<<"00";
					
				}
				
			}else if( s[1][2] <= 'F' && s[1][2] >='D' ){
				
				if(  s[2][2] <= 'F' && s[2][2] >='D' ){
					
					cout<<"11";
					
				}else{
					
					cout<<"00";
					
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