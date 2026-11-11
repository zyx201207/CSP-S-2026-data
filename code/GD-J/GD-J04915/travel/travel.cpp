#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(stoll(c1)==stoll(c2)){
		cout<<1;
		if(stoll(s1)==stoll(s2)){
			cout<<1;
			if(s1[2]<='C' and s2[2]<='C' or s1[2]>='D' and s2[2]>='D'){
				cout<<1;
				if(abs(s1[2]-s2[2])==1) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
}
