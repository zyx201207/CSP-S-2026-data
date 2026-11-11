#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int l,r;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(b[2]=='D'||b[2]=='F'){
		l=1;
	}
	else l=2;
	if(d[2]=='D'||d[2]=='F'){
		r=1;
	}
	else r=2;
	if(a!=c){
		cout<<"0000";
	}
	else{
		for(int i=0;i<3;i++){
			if(i==0){
				if(b[i]!=d[i]){
					cout<<"1000";
					break;
				}
			}
			if(i==1){
				if(b[i]!=d[i]){
					cout<<"1000";
					break;
				}
			}
			if(i==2){
				if(l!=r){
					cout<<"1100";
					break;
				}
				else if(l==r&&l==1){
					cout<<"1111";
				}
				else if(l==r){
					if(b[2]=='C'&&d[2]=='B'){
						cout<<"1111";
						break;
					}
					else if(b[2]=='B'&&d[2]=='C'){
						cout<<"1111";
						break;
					}
					else if(b[2]=='B'&&d[2]=='A'){
						cout<<"1111";
						break;
					}
					else if(b[2]=='A'&&d[2]=='B'){
						cout<<"1111";
						break;
					}
					else{
						cout<<"1110";
						break;
					} 
				}
			}
		}
	}
	return 0;
}
//02 01C 02 01D
