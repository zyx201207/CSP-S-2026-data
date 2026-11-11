#include<bits/stdc++.h>
using namespace std;
string b,y,a,x;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>x>>y;
	if(a!=x){
		cout<<"0000";
	}else{
		cout<<1;
		if(b[0]==y[0]&&b[1]==y[1]){
			cout<<1;
			if((b[2]<='C'&&y[2]<='C')||(b[2]>='D'&&y[2]>='D')){
				cout<<1;
			if(abs(b[2]-y[2])<=1){
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
	}
	return 0;
}
