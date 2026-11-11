#include<bits/stdc++.h>
using namespace std;
int main(){
	char c[5]={},r[5]={};
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	for(int i=1;i<=5;i++){
		cin>>c[i];
		//cout<<c[i]<<"1";
		//ÊäÈëc 
	}
	for(int i=1;i<=5;i++){
		cin>>r[i];
		//cout<<r[i]<<"1";
		//ÊäÈër 
	}
	if(c[1]==r[1]&&c[2]==r[2]){
		cout<<"1";
		if(c[3]==r[3]&&c[4]==r[4]){
			cout<<"1";
			if((c[5]-'C'<=0&&r[5]-'C'<=0)||(c[5]-'C'>0&&r[5]-'C'>0)){
				cout<<"1";
				if(abs(c[5]-r[5])==1){
					cout<<"1";
				}
				else{
					cout<<"0";
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
