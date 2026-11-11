#include<bits/stdc++.h>
using namespace std;
string a[3],b[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a[1]>>b[1]>>a[2]>>b[2];
	if(a[1]!=a[2]){
		cout<<"0000\n";
		return 0;
	}else{
		cout<<"1";
		if(b[1][0]+b[1][1]!=b[2][0]+b[2][1]){
			cout<<"000\n";
			return 0;
		}else{
			cout<<"1";
			if(b[1][2]<='C' and b[2][2]<='C'){
				cout<<"1";
				if(abs(b[1][2]-b[2][2])<=1){
					cout<<"1\n";
				}else cout<<"0\n";
			}else if(b[1][2]>'C' and b[1][2]<='F' and b[2][2]>'C' and b[2][2]<='F'){
				cout<<"1";
				if(abs(b[1][2]-b[2][2])<=1){
					cout<<"1\n";
				}else cout<<"0\n";
			}else cout<<"00\n";
		}
	}
	return 0;
}
