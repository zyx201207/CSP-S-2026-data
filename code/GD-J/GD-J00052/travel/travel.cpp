#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a,b,ap,bp;
	char ca,cb;
	cin>>a>>ap>>ca>>b>>bp>>cb;
	if(a!=b){
		cout<<"0000";
	}else{
		cout<<"1";
		if(ap!=bp){
			cout<<"000";
		}else{
			cout<<"1";
			if((ca<='C')!=(cb<='C')){
				cout<<"00";
			}else{
				cout<<"1";
				if(abs((int)ca-cb)==1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}
		}
	}
	return 0;
} 
