#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m;string x,y,a,b;char l,r;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>y>>a>>b;if(y[2]<b[2]){l=y[2];r=b[2];}
	else {r=y[2];l=b[2];}//cout<<l<<r;
	if(x==a){
		cout<<"1";
		if(y[0]==b[0]&&y[1]==b[1]){cout<<"1";
			if((r-l==1&&l!='C'&&r!='D')||(l=='A'&&r=='C')){
			cout<<"1";if(r-l==1)cout<<"1";else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
