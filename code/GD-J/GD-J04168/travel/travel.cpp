#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		bool k=0;
		for(int i=0; i<=1; i++){
			if(b[i]!=d[i]){
				k=1;
			}
		}
		if(k==0){
			cout<<1;
			int k=b[2]-'A';
			int k2=d[2]-'A';
			if(k>=0&&k<=2){
				if(k2>=0&&k2<=2){
					cout<<1;
					if(abs(k2-k)==1){
						cout<<1;
					}
					else{
						cout<<0;
					}
				}
				else{
					cout<<"00";
				}
			}
			else if(k==3||k==5){
				if(k2==3||k2==5){
					cout<<"11"; 
				}
				else{
					cout<<"00";
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
//Trick||Treat!
