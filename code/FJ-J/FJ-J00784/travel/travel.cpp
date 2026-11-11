#include<bits/stdc++.h>
using namespace std;
int ca,cb,za,zb;
char a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>za>>a>>cb>>zb>>b;
	if(ca!=cb) cout<<"0000";
	else{
		cout<<1;
		if(za!=zb) cout<<"000";
		else{
			cout<<1;
			if(a-'A'>2 && b-'A'<3 || a-'A'<3 && b-'A'>2) cout<<"00";
			else{
				cout<<1;
				if(abs(a-b)!=1) cout<<0;
				else cout<<1;
			}
		}
	}
	return 0;
}
