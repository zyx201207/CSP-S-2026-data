#include <iostream>
using namespace std;
int main(){
	freopen("travel5.in","r",stdin);
	freopen("travel5.out","w",stdout);
	int n,x;
	char m[5]={},y[5]={};
	cin>>n;
	cin>>m;
	cin>>x;
	cin>>y;
	if(n==x){
		cout<<"1";
		if(m[0]==y[0]&&m[1]==y[1]){
			cout<<"1";
			if(m[2]>='A' && m[2]<='C'){
				if(y[2]=='A'||y[2]<='C'){
					cout<<"1";
					if(m[2]-1==y[2]||m[2]+1==y[2]){
						cout<<'1';
					}else{
						cout<<'0';
					}
				}else{
					cout<<"00";
				}
			}else{
				if(y[2]>='A'&&y[2]<='C'){
					cout<<"00";
				}else{
					cout<<"1";
					if(m[2]-1==y[2]||m[2]+1==y[2]){
						cout<<'1';
					}else{
						cout<<'0';
					}
				}
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
