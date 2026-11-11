#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string c1,c2;
    int s11,s21;
	char s12,s22;
	cin>>c1>>s11>>s12>>c2>>s21>>s22;
	if(c1==c2){
		if(s11==s21){
			if(s12=='A'){
				if(s22=='B'){
					cout<<"1111";
				}
				if(s22=='C'){
					cout<<"1110";
				}
				if(s22=='D'||s22=='F'){
					cout<<"1100";
				}
			}
			else if(s12=='B'){
				if(s22=='C'){
					cout<<"1111";
				}
			
			else if(s12=='B'){
				if(s22=='A'){
					cout<<"1111";
				}
				if(s22=='A'||s22=='C'){
					cout<<"1111";
				}
				if(s22=='D'||s22=='F'){
					cout<<"1100";
				}
			}
			else if(s12=='C'){
				if(s22=='D'||s22=='F'){
					cout<<"1100";
				}
				if(s22=='A'){
					cout<<"1110";
			    }
				if(s22=='B'){
					cout<<"1111";
				}
			}
			else if(s12=='D'){
				if(s22=='A'||s22=='B'||s22=='C'){
					cout<<"1100";
				}
				if(s22=='F'){
					cout<<"1111";
				}
			}
			else if(s12=='F'){
				if(s22=='A'||s22=='B'||s22=='C'){
					cout<<"1100";
				}
				if(s22=='D'){
					cout<<"1111";
				}
			}
		}
		
	}else{
			cout<<"1000";
		}
	}
	else{
		cout<<"0000";
	}
	
return 0;
}
