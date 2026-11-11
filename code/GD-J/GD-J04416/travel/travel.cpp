#include<fstream>
#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string in[4];
	for(int i = 0;i<4;i++){
		cin>>in[i];
	}
	bool a = 0,b = 0,c = 0,d = 0;
	if(in[0]==in[2]){
		a = 1;
		if(stoi(in[1])==stoi(in[3])){
			b=1;
			if((in[1][2]>='D'&&in[3][2]>='D')||(in[1][2]<='C'&&in[3][2]<='C')){
				c=1;
				if(in[1][2]-in[3][2]==1||in[1][2]-in[3][2]==-1){
					d=1;
				}
			}
		}
	}
	cout<<a<<b<<c<<d;
	return 0;
}
