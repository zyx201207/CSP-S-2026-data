#include<bits/stdc++.h>
using namespace std;
int a,b;
char c[5],d[5],m[7]={"ABCDF"};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a;
	for(int i=0;i<3;i++){
		cin>>c[i];
	}
	cin>>b;
	for(int i=0;i<3;i++){
		cin>>d[i];
	}
	if(a==b){
		cout<<"1";
		if(c[1]==d[1]&&c[0]==d[0]){
			cout<<"1";
			if((c[2]==m[0]||c[2]==m[1]||c[2]==m[2])&&(d[2]==m[0]||d[2]==m[2]||d[2]==m[1])){
				cout<<"1";
				if(int(c[2])-1==int(d[2])||int(c[2])+1==int(d[2])){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else if(c[2]==m[3]&&d[2]==m[4]){
				cout<<"11";
			}else if(c[2]==m[3]&&d[2]==m[4]){
				cout<<"11";
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
