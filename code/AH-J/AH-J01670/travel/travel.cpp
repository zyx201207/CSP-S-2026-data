#include<bits/stdc++.h>
using namespace std;
int a,b;
string s1,s2;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>s1>>b>>s2;
	if(a==b)cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(abs(s1[2]-s2[2])==1){
		cout<<1;
	}else{
		cout<<0;
	}

}
