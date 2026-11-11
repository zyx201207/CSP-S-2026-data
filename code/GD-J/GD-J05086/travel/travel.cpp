#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+5,M=5e3+3;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1;
	string c2,s2;
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1){
		cout<<1;
		if(c2[0]==s2[0]&&c2[1]==s2[1]){
			cout<<1;
			if(c2[2]>='D'&&s2[2]>='D'||c2[2]<='C'&&s2[2]<='C'){
				cout<<1;
				if(c2[2]>='D'&&s2[2]>='D'||!((c2[2]=='C'||c2[2]=='A')&&(s2[2]=='C'||s2[2]=='A'))){
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	} 
	else cout<<"0000";
	return 0;
}

