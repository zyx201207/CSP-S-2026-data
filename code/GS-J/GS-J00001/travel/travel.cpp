#include<bits/stdc++.h>
using namespace std;
#define itn int
#define inl inline
#define re register
#define pos ios::sync_with_stdio(NULL);cin.tie(0);cout.tie(0);
//开long long了否
//数组大小足够否
//freopen去掉注释了否 
string c1,c2,s1,s2;
signed main(){
	freopen("r","travel.in",stdin);
	freopen("w","travel.out",stdout);
	pos;
	cin>>c1>>s1>>c2>>s2;
	if(!(c1==c2)){
		cout<<"0000";
		return 0;
	}
	string t1=s1.substr(0,s1.size()-1),t2=s2.substr(0,s2.size()-1);
	//cout<<t1<<'\n'<<t2<<'\n';
	if(!(t1==t2)){
		cout<<"1000";
		return 0;
	}
	char a=s1[s1.size()-1],b=s2[s2.size()-1];
	if((a=='C'&&b=='D')||(a=='D'&&b=='C')){
		cout<<"1100";
		return 0;
	}
	if(!(b-a==1||a-b==1)){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
