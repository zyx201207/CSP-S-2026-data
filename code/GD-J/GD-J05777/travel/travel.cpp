#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	//for(int i=0;i<2;i++){
		if(c1[0]==c3[0]&&c1[1]==c3[1]){
			cout<<1;
			for(int i=0;i<1;i++){
				if(c2[0]==c4[0]&&c2[1]==c4[1]){
					cout<<1;
					if(c2[2]=='D'||c2[2]=='F'&&c4[2]=='D'||c4[2]=='F'){
						cout<<1;
						if(c2[2]=='D'&&c4[2]=='F'||c2[2]=='F'&&c4[2]=='D') cout<<1;
						else{
							cout<<0;
							break;
						}
					}
					else{
						cout<<0<<0;
						break;
					}
					if(c2[2]=='A'||c2[2]=='B'||c2[2]=='C'&&c4[2]=='A'||c4[2]=='B'||c4[2]=='C'){
						cout<<1;
						if(c2[2]=='A'&&c4[2]=='B'||c2[2]=='B'&&c4[2]=='C'||c2[2]=='B'&&c4[2]=='A'||c2[2]=='C'&&c4[2]=='B') cout<<1;
						else{
							cout<<0;
							break;
						}			
					}
					else{
						cout<<0<<0;
						break;
					}
				}
				else{
					cout<<0<<0<<0;
					break;
				}
			}
		}
		else{
			cout<<0<<0<<0<<0;
			//break;
		}
	//}
	return 0;
} 
