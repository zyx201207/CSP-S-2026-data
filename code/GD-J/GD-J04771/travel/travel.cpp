#include<bits/stdc++.h> 
#define ll long long
using namespace std;
const int N=1e5+10;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		if(b[0]==d[0] and b[1]==d[1]){
			cout<<1;
			if(b[2]<='C' and d[2]<='C'){
				if(b[2]=='A' and d[2]=='C' or b[2]=='C' and d[2]=='A'){
					cout<<"10";
				}else{
					cout<<"11";
				}
			}else if(b[2]>'C' and c[2]>'C'){
				cout<<"11";
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
