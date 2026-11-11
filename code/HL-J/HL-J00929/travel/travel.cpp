#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s1,s2,s3,s4;cin>>s1>>s2>>s3>>s4;
	if(s1==s3)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	string l_1=s2.substr(0,2);
	string l_2=s4.substr(0,2);
	if(l_1==l_2)cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	char w_1=s2[2];char w_2=s4[2];
	bool flag=1;
	if((w_1<='C'&&w_2<='C')||(w_1>='D'&&w_2>='D'))cout<<1;
	else{
		flag=0;cout<<0;
	}
	if(flag){
		if(w_2<w_1)swap(w_2,w_1);
		if((int)(w_2)-(int)(w_1)==1)cout<<1;
		else cout<<0;
	}
	else cout<<0;
}