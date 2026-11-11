#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cc1,ss1,cc2,ss2;
	cin>>cc1>>ss1>>cc2>>ss2;
	
	if(cc1[0]!=cc2[0]||cc1[1]!=cc2[1]){
		cout<<"0000";
		return 0;
	}
	if(ss1[0]!=ss2[0]||ss1[1]!=ss2[1]){
		cout<<1000;
		return 0;
	}
	if(ss1[2]<='C'&&ss2[2]>='D'){
	cout<<1100;
	return 0;
}
	else if(ss2[2]<='C'&&ss1[2]>='D'){
	cout<<1100;
	return 0;
}	
	if(ss1[2]-ss2[2]==1||ss2[2]-ss1[2]==1){
		cout<<1111;
		return 0;
	}
	else cout<<1110;
	return 0;

}
