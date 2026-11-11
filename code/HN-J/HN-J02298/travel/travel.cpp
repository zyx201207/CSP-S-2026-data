#include<iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool a[4]={0}; 
	char c[3][6];
	for(int i=1;i<=2;i++){
		for(int j=1;j<=5;j++){
			cin>>c[i][j];
		}
	}
	if(c[1][1]==c[2][1]&&c[1][2]==c[2][2]){
		a[0]=1;	
		if((c[1][3]==c[2][3])&&(c[1][4]==c[2][4])){
			a[1]=1;
			if(((c[1][5]<='C')&&(c[2][5]<='C'))||((c[1][5]>'C')&&(c[2][5]>'C'))){
				a[2]=1;
				if(c[1][5]-c[2][5]==1||c[1][5]-c[2][5]==-1)a[3]=1;
			}
		}
	}
	for(int i=0;i<4;i++){
		cout<<a[i];
	}
	return 0;
}
