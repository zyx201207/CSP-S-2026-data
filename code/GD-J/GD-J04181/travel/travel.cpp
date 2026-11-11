#include<bits/stdc++.h>
using namespace std;
int a,b;
string A,B;
bool Side(char x,char y){
	if(x<='C'&&y<='C')return 1;
	else if(x>'C'&&y>'C')return 1;
	else return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>A>>b>>B;
	if(a==b){
		cout<<1;
	}
	else cout<<0;
	if(a==b&&A[0]==B[0]&&A[1]==B[1])cout<<1;
	else cout<<0;
	if(a==b&&A[0]==B[0]&&A[1]==B[1]&&Side(A[2],B[2]))cout<<1;
	else cout<<0;
	if(a==b&&A[0]==B[0]&&A[1]==B[1]&&Side(A[2],B[2])&&abs(int(A[2]-B[2]))==1)cout<<1;
	else cout<<0;
	return 0;
} 
