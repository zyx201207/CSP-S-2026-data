#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("trsvel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string R,X;
	string r,x;
	cin>>R>>r>>X>>x;
	//cout<<R<<' '<<r<<' '<<X<<' '<<x;
	if(R==X){
		cout<<1;
		if(r[0]+r[1]==x[0]+x[1]){
			cout<<1;
			if((r[2]>='D'&&x[2]>='D')||(r[2]<='C'&&x[2]<='C')){
				cout<<1;
				if(abs(r[2]-x[2])==1){
					cout<<1;
					return 0;
				} 
				cout<<0;
			}
			cout<<"00";
			return 0;
		}
		cout<<"000";
		return 0;
	}
	cout<<"0000";
} 
