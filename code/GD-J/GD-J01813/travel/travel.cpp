#include<bits/stdc++.h>
using namespace std;
string s1,s2,t1,t2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>s1>>s2>>t1>>t2;
	if(s1==t1){
		cout<<1;
		if(s2[0]==t2[0]&&s2[1]==t2[1]){
			cout<<1;
			if((s2[2]<='C'&&t2[2]<='C')||(s2[2]>='D'&&t2[2]>='D')){
				cout<<1;
				if(abs(s2[2]-t2[2])==1) cout<<1;
				else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}

