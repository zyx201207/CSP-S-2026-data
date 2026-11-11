#include<bits/stdc++.h>
#define int long long
using namespace std;
inline bool side(char a){
	if(a=='A'||a=='B'||a=='C')return 1;
	else return 0;
}
inline void checker(char c1,char c2){
	if(c1>c2){
		swap(c1,c2);
	}
	bool b1=side(c1),b2=side(c2);
	if(b1==b2){
		if(c1+1==c2){
			cout<<"11";
		}else cout<<"10";
	}else cout<<"00";
	return;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int a1,b1,a2,b2;
	char c1,c2,temp;
	cin>>a1>>b1>>c1>>temp>>a2>>b2>>c2;
	if(a1==a2){
		cout<<"1";
		if(b1==b2){
			cout<<"1";
			checker(c1,c2);
		}
		else cout<<"000";
		
	}
	else{
		cout<<"0000";
	}
	return 0;
}
