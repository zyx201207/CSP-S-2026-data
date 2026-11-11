#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2;
	char w1[4],w2[4];
	cin>>c1>>w1>>c2>>w2;
	if(c1==c2){
		cout<<"1";
		if(w1[0]==w2[0]&&w1[1]==w2[1]){
			cout<<"1";
			if(w1[2]>='A'&&w1[2]<='C'&&w2[2]>='A'&&w2[2]<='C'){
				cout<<"1";
				int d=abs(w1[2]-w2[2]);
				if(d==1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else if(w1[2]>='D'&&w1[2]<='E'&&w2[2]>='D'&&w2[2]<='E'){
				cout<<"11";
			}else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
