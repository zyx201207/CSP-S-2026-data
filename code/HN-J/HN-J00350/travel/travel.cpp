#include<bits/stdc++.h>
using namespace std;
string rzw,xzw;
int r,x;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r>>rzw>>x>>xzw;
	if(r==x){
		cout<<"1";
		if(rzw[0]==xzw[0]&&rzw[1]==xzw[1]){
			cout<<"1";
			if(rzw[2]<='C'&&xzw[2]<='C' || rzw[2]>='D'&&xzw[2]>='D'){
				cout<<"1";
				if(rzw[2]<='C'&&xzw[2]<='C'){
					if(abs(int(rzw[2])-int(xzw[2]))==1){
						cout<<"1";
					}
					else{
						cout<<"0";
						return 0;
					}
				}
				else if(rzw[2]>='D'&&xzw[2]>='D'){
					cout<<"1";
				}
				
			}
			else{
				cout<<"00";
				return 0;
			}
			
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	return 0;
}  
