#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1, s1, c2, s2;
void solve(){
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
				cout<<1;
				if(abs(s1[2]-s2[2])==1){
					cout<<1;
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
}
signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int _=1;
//	cin>>_;
	while(_--){
		solve();
	}
}
/*
想上迷惑行为大赏(luogu:1451514)
估分：100+100+100+48
下面的是用来骗你进来的 
freopen("ans.in", "r", stdin)
freopen("srting.in", "r", stdin)
freopen("traval.in", "r", stdin)
freopen("crad.in", "r", stdin)
freopen(".in", "r", stdin)
froopen(".in", "r", stdin)
feropen(".in", "r", stdin)
frepoen(".in", "r", stdin)
*/
