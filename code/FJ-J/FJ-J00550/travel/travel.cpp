#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]=='F')s1[2]='E';
	if(s2[2]=='F')s2[2]='E';
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	int flag1=(s1[0]-48)*10+(s1[1]-48);
	int flag2=(s2[0]-48)*10+(s2[1]-48);
	if(flag2!=flag1){
		cout<<"000";
		return 0;
	}
	cout<<1;
	int f1=(s1[2]-'A'),f2=(s2[2]-'A');
	if((f1<=2&&f2>2)||(f1>2&&f2<=2)){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(abs(f1-f2)==1){
		cout<<1;
		return 0;
	}
	cout<<0;
	return 0;
}
