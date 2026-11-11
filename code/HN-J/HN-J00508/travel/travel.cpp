#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b;
string x,y;
signed main(){
	cin>>a>>x>>b>>y;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	if(a==b){
		cout<<1;
		if(x[0]==y[0]&&x[1]==y[1]){
			cout<<1;
			if(x[2]>='A'&&x[2]<='C'&&y[2]>='A'&&y[2]<='C'){
				cout<<1;
				if((char)(x[2]+1)==y[2]||(char)(x[2]-1)==y[2])cout<<1;
				else cout<<0;
			}else if(x[2]>='D'&&x[2]<='F'&&y[2]>='D'&&y[2]<='F'){
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
