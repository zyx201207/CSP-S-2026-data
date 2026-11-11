#include<bits/stdc++.h>
using namespace std;
int A;
long int n; 
int Q[200005];
char c[200005];
int con;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);	
string a; 
cin>>n;
for(int i=1;i<=n;i++){
	cin>>Q[i];
	cin>>c[i];
	con=con+Q[i];
	if(c[i]!=c[i-1]){
		if(i!=1)A=1;
	}
	
}
	if(A==0){
		cout<<0;
	}	
	else{
		cout<<con/2;
}
	return 0;
} 
