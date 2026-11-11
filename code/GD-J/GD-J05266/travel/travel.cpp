#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(int i=0;i<4;i++){
		cin>>a[i];
	}
	string texr = a[1].substr(0,2);
	string texx = a[3].substr(0,2);
	if(a[0]==a[2]){
		cout<<1;
		
		if(texr==texx){
			cout<<1;
			if(a[1][2]<='C'&&a[3][2]<='C'||a[1][2]>'C'&&a[3][2]>'C'){
				cout<<1;
				if(abs(a[1][2]-a[3][2])==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<0<<0;
			}
		}
		else{
			cout<<0<<0<<0;
		}
	}
	else{
		cout<<0<<0<<0<<0;
	}
	
	return 0;
}
