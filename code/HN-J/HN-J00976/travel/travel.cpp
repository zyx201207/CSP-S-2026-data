#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	char a,b,c,d,e,aa,bb,cc,dd,ee;
	cin>>a>>b>>c>>d>>e>>aa>>bb>>cc>>dd>>ee;
	if(a==aa&&b==bb){
		cout<<1;
		if(c==cc&&d==dd){
			cout<<1;
			if(e<='C'&&ee<='C'||e>='D'&&ee>='D'){
				cout<<1;
				int xxx=e-'A';
				int yyy=ee-'A';
				if(abs(xxx-yyy)>1||abs(xxx-yyy)<1){
					cout<<0;
				}else{
					cout<<1;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
