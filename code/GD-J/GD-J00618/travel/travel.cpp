#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,c;
	char b[5],d[5];
	cin>>a;
	for(int i=0;i<3;i++){
		cin>>b[i];
	}
	cin>>c;
	for(int i=0;i<3;i++){
		cin>>d[i];
	}
	if(a==c){
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1;
			if((b[2]<='C'&&b[2]>='A')&&(d[2]>='A'&&d[2]<='C')){
				cout<<1;
				if(b[2]<d[2]){
					if(int(b[2]+1)==int(d[2])){
						cout<<1;
						return 0;
					}else{
						cout<<0;
						return 0;
					}
				}
				if(d[2]<b[2]){
					if(int(d[2]+1)==int(b[2])){
						cout<<1;
						return 0;
					}else{
						cout<<0;
						return 0;
					}
				}
			}else if((b[2]<='F'&&b[2]>='D')&&(d[2]>='D'&&d[2]<='F')){
				cout<<"11";
				return 0;
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
