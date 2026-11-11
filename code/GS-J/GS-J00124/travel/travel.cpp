#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	bool f=0,q=0,z=0;
	if(a==c){
		z=1;
		cout<<1;
	}else{
		cout<<0;
	}
	if(z&&b[0]==d[0]&&b[1]==d[1]){
		cout<<1;
		if((b[2]>='A'&&d[2]<='C'||b[2]>='D'&&d[2]<='F')){
			cout<<1;
			if(int(b[2])+1==int(d[2])||int(d[2])+1==int(b[2])){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<"00";
		}
	}else{
		cout<<"000";
	}
	
	
	return 0;
}
