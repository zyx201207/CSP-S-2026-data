#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie();
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
	}else{
		cout<<1;
		char e=b[0],f=b[1],g=d[0],h=d[1];
		if(e==g && f==h){
			cout<<"1";
			int i=b[2]-'A',j=d[2]-'A';
			if(i<j) swap(i,j);
			if(i==5) i--;
			if(i>=3 && j<=2) {
				cout<<"00";
			}else{
				cout<<"1";
				if(i!=j+1){
					cout<<"0";
				}else{
					cout<<"1";
				}
			}
		} else{
			cout<<"000";
		}
	}
	return 0;
} 
