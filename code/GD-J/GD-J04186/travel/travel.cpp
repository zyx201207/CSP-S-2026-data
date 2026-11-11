#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x,y,x1,y1;
	cin>>x1>>x>>y1>>y;
	if(x1==y1){
		cout<<1;
		if((x[0]==y[0])&&(x[1]==y[1])){
			cout<<1;
			if(((x[2]<='C'&&x[2]>='A')&&(y[2]<='C'&&y[2]>='A'))||((x[2]<='F'&&x[2]>='D')&&(y[2]<='F'&&y[2]>='D'))){
				cout<<1;
				if((x[2]-1==y[2])||(y[2]-1==x[2])){
					cout<<1;
				}
				else{
					if(y[2]-2==x[2]){
						cout<<1;
					}
					else{
						cout<<0;
					}
			}
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
	}
	
	
	return 0;
} 
