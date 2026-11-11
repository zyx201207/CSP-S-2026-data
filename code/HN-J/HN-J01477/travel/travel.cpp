#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int gc1,gc2,ss1,ss2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2; 
	if(c1==c2){
		cout<<1;
		for(int i=0;i<=1;i++){
			gc1=gc1*10+(s1[i]-'0');
			gc2=gc2*10+(s2[i]-'0');
		}
		if(gc1==gc2){
			cout<<1;
			ss1=s1[2]-'A';
			ss2=s2[2]-'A';
			if(ss1<=2 and ss2<=2){
				cout<<1;
				if(abs(ss1-ss2)==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else if(ss1>=3 and ss2>=3){
				cout<<11;
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000"; 
		return 0;
	}
	return 0;
} 
