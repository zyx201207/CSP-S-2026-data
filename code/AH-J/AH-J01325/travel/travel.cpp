#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x2,x,y2,y;
	cin>>x2>>x>>y2>>y;
	if(x2!=y2){
		cout<<"0000";
		return 0;
	}
	if(x[0]!=y[0]||x[1]!=y[1]){
		cout<<"1000";
		return 0;
	}
	if((x[2]<='C'&&y[2]>='D')||(y[2]<='C'&&x[2]>='D')){
		cout<<"1100";
		return 0;
	}
	if((x[2]=='A'&&y[2]=='C')||(x[2]=='C'&&y[2]=='A')){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
