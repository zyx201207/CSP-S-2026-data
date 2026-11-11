#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string A,B,C,D;
bool c[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>A>>C>>B>>D;
	if(A[0]==B[0]&&A[1]==B[1])c[0]=1;
	if(C[0]==D[0]&&C[1]==D[1]&&c[0]==1)c[1]=1;
	if(c[1]==1){
		if(C[2]>='D'&&D[2]>='D'){
			c[2]=1;
		}
		else if(C[2]<='C'&&D[2]<='C'){
			c[2]=1;
		}
	}
	if(c[0]==1&&c[1]==1){
		if(C[2]=='A'&&D[2]=='B')c[3]=1;
		if(D[2]=='A'&&C[2]=='B')c[3]=1;
		if(C[2]=='B'&&D[2]=='C')c[3]=1;
		if(D[2]=='B'&&C[2]=='C')c[3]=1;
		if(C[2]=='D'&&D[2]=='F')c[3]=1;
		if(D[2]=='D'&&C[2]=='F')c[3]=1;
	}
	cout<<c[0]<<c[1]<<c[2]<<c[3];
	return 0;
}
