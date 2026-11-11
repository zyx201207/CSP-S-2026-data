#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a[2],c[2];
	char b[3],d[3];
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]){
		cout<<"1";
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<"1";
			if(b[2]<='C'&&d[2]<='C'){
				cout<<"1";
				if((b[2]+1)==d[2]||(d[2]+1)==b[2]){
					cout<<"1";
				}else cout<<"0";
			}else if(b[2]>='D'&&d[2]>='D'){
				cout<<"1";
				if((b[2]+1)==d[2]||(d[2]+1)==b[2]){
					cout<<"1";
				}else cout<<"0";
			}else{
				cout<<"0";
				cout<<"0";
			}
		}else{
			cout<<"0";
		    cout<<"0";
		    cout<<"0";
		}
	}else{
		cout<<"0";
		cout<<"0";
		cout<<"0";
		cout<<"0";
	}
	return 0;
}
