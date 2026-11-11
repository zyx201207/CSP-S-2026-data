#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string n,m;
	cin>>n>>m;
	string x,y;
	cin>>x>>y;
	if(x!=n){
		cout<<"0000";
	} 
	else{
		cout<<"1";
		if(y[0]!=m[0]||y[1]!=m[1]){
			cout<<"000";
		}
		else{
			cout<<"1";
			char a=m[2],b=y[2];
			if(a<='C'&&b>='D'||a>='D'&&b<='C'){
				cout<<"00";
			}
			else{
				cout<<"1";
				int q=abs(a-b);
				if(q==1){
					cout<<"1";
				}
				else cout<<"0";
			}
		}
	}
	return 0;
} 
