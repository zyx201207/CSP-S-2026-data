#include<bits/stdc++.h>
using namespace std;
int A,B,C,D,F; 
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a[1]==c[1] and a[2]==c[2]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(a[1]==c[1] and a[2]==c[2] and b[0]==d[0] and b[1]==d[1]){
		cout<<1;	
	}
	else{
		cout<<0;
	}
	if(a[1]==c[1] and a[2]==c[2] and b[0]==d[0] and b[1]==d[1] and ((b[3]==char(A) and d[3]==char(B)) or (b[3]==char(A) and d[3]==char(C)) or (b[3]==char(B) and d[3]==char(C)) or (b[3]==char(B) and d[3]==char(A)) or (b[3]==char(C) and d[3]==char(A)) or (b[3]==char(C) and d[3]==char(B)) or (b[3]==char(D) and d[3]==char(F)) or (b[3]==char(F) and d[3]==char(D)))){
			cout<<1;
	}
	else{
		cout<<0;
	}
	if(a[1]==c[1] and a[2]==c[2] and b[0]==d[0] and b[1]==d[1] and ((b[3]==char(A) and d[3]==char(B)) or(b[3]==char(B) and d[3]==char(C)) or (b[3]==char(B) and d[3]==char(A)) or (b[3]==char(C) and d[3]==char(B)) or (b[3]==char(D) and d[3]==char(F)) or (b[3]==char(F) and d[3]==char(D)))){
			cout<<1;	
		}
	else{
		cout<<0;
	}	
}
