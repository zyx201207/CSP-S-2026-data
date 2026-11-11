#include<bits/stdc++.h>
using namespace std;

string s1,s2,c1,c2;

void solve(){
	if(c1[1]==c2[1]&&c1[0]==c2[0]){
		cout<<1;
	}else{
		cout<<"0000";
		return;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<"000";
		return;
	}
	bool f1=(s1[2]<='C'),f2=(s2[2]<='C');
	if(f1==f2){
		cout<<1;
	}else{
		cout<<"00";
		return;
	}
	if(abs(s1[2]-s2[2])==1)cout<<1;
		else cout<<0;
}


int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	solve();
	return 0;
}
