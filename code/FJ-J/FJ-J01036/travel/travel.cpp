#include<bits/stdc++.h>
#define int long long
using namespace std;

map<char,int> mp;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	string b1="",d1="";
	int b2,d2;
	mp['A']=1;
	mp['B']=2;
	mp['C']=3;
	mp['D']=4;
	mp['F']=5;
	b1+=b[0];
	b1+=b[1];
	b2=mp[b[2]];
	d1+=d[0];
	d1+=d[1];
	d2=mp[d[2]];
	if(a!=c){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(b1!=d1){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	if((b2==4&&d2==5)||(b2==5&&d2==4)){
		cout<<"11";
		return 0;
	}
	if(((b2<=3&&d2>=4)||(b2>=4&&d2<=3))){
		cout<<"00";
		return 0;
	}
	cout<<"1";
	if(b2-d2==1||d2-b2==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}

