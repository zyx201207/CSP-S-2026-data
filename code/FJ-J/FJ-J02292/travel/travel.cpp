#include <bits/stdc++.h>
using namespace std;

int a1,a2; 
char p11,p12,p13,p21,p22,p23;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	cin>>a1;
	cin>>p11;
	cin>>p12;
	cin>>p13;
	cin>>a2;
	cin>>p21;
	cin>>p22;
	cin>>p23;
	
	if(a1 == a2){
		cout<<1;
		if(p11 == p21 && p12 == p22){
			cout<<1;
			if((p13 - 'A' <= 2 && p23 - 'A' <= 2) || (p13 - 'A' > 2 && p23 - 'A' > 2)){
				cout<<1;
				if(abs(p13-p23) == 1){
					cout<<1;
				}else{
					cout<<0;
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
