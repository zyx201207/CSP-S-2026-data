#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,a1,b1,b;
	cin >>a >>a1 >>b >>b1;
	if(a1==b1){
		cout <<0;
		cout <<0;
		cout <<0;
		cout <<0;
	}else{
		if(a==b){
			cout <<1;
		}else{
			cout <<0;
		}
		if(a1[0]==b1[0]&&a1[1]==b1[1]){
			cout <<1;
		}else{
			cout <<0;
		}
		if(a1[2]<='C'&&b1[2]<='C'||a1[2]>='D'&&b1[2]>='D'){
			cout <<1;
		}else{
			cout <<0;
		}
		int A=a1[2],B=b1[2];
		if(!(a1[2]!='C'&&b1[2]!='D'||a1[2]!='D'&&b1[2]!='C')&&A==B-1||A==B+1){
			cout <<1;
		}else{
			cout <<0;
		}
	}
		
	return 0;
}
