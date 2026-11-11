#include<iostream>
#include<cstring>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	int cx[2],bhy[2];
	char bhx[2];
	cin>>cx[0]>>bhy[0]>>bhx[0];
	cin>>cx[1]>>bhy[1]>>bhx[1];
	char a='0',b='0',c='0',d='0';
	if(cx[0]==cx[1]){
		a='1';
		if(bhy[0]==bhy[1]){
			b='1';
			if(((bhx[0]=='A'||bhx[0]=='B'||bhx[0]=='C')&&(bhx[1]=='A'||bhx[1]=='B'||bhx[1]=='C'))||((bhx[0]=='D'||bhx[0]=='E')&&(bhx[1]=='D'||bhx[1]=='E'))){
				c='1';
				if(bhx[0]-bhx[1]==1||bhx[1]-bhx[0]==1){
					d='1';
				}
			}
		}
	}
	cout<<a<<b<<c<<d;
	return 0;
} 
