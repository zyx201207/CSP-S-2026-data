#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	string a,b;
	cin>>n;
	for(int i = 1;i<=3;i++){
		cin>>a[i];
	}
	cin>>m;
	for(int i = 1;i<=3;i++){
		cin>>b[i];
	}
	if(n!=m){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<"1";
		if(a[1] == b[1] && a[2] == b[2]){
			cout<<"1";
			if(a[3] == 'D'){
				if(b[3] == 'F'){
					cout<<"11";
					return 0;
				}
			}else if(a[3] == 'F'){
				if(b[3] == 'D'){
					cout<<"11";
					return 0;
				}	
			}else if(a[3] == 'A'){
				if(b[3] == 'B'){
					cout<<"11";
					return 0;
				}
				if(b[3] == 'C'){
					cout<<"10";
					return 0;
				}	
			}
			else if(a[3] == 'B'){
				if(b[3] == 'A' || a[3] == 'C'){
					cout<<"11";
					return 0;
				}	
			}
			else if(a[3] == 'C'){
				if(b[3] == 'B'){
					cout<<"11";
					return 0;
				}
				if(b[3] == 'A'){
					cout<<"10";
					return 0;
				}	
			}
			cout<<"00";
		}
		else{
			cout<<"000";
		}
	}
	return 0;
}
