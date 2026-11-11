#include<bits/stdc++.h>
using namespace std;
string a1,b1,a2,b2;
int x;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a1>>b1>>a2>>b2;
	if(a1==a2){
		cout<<1;
		if(b1[0]==b2[0] && b1[1]==b2[1]){
			cout<<1;
			if(b1[2]<='C' && b2[2]<='C'){
				cout<<1;
				if(b1[2]>=b2[2]){
					x=b1[2]-b2[2];
				}
				else{
					x=b2[2]-b1[2];
				}
				if(x==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else if(b1[2]>'C' && b2[2]>'C'){
				for(int i=1;i<=2;i++){
					cout<<1;
				}
			}
			else{
				for(int i=1;i<=2;i++){
					cout<<0;
				}
			}
		}
		else{
			for(int i=1;i<=3;i++){
				cout<<0;
			}
		}
	}
	else{
		for(int i=1;i<=4;i++){
			cout<<0;
		}
	}
	return 0;
} 
