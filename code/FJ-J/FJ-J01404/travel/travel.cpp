#include<bits/stdc++.h>
using namespace std;
int main(){
	string s,ss;
	string a,aa;
	cin>>s>>a>>ss>>aa;
	bool b;
	if(s == ss){
		b = 1;
	}else{
		b = 0;
	}
	if(b){
		cout<<"1";
		if(a[0] == aa[0]&&a[1] == aa[1]){
			cout<<"1";
			if(a[2]>='D'&&aa[2]>='D'){
				cout<<"11";
			}else if(a[2]<='C'&&aa[2]<='C'){
				cout<<"1";
				if(abs(a[2]-aa[2]) == 1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
} 
