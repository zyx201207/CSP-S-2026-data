#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=1e5+10;
const int M=1e6+10;
const int K=15;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
string a,b,c,d,ans;
int check(char ch){
	if(ch=='A')return 1;
	if(ch=='B')return 1;
	if(ch=='C')return 1;
	if(ch=='D')return 2;
	if(ch=='F')return 2;
	return 0;
}
int get_val(char ch){
	if(ch=='A')return 1;
	if(ch=='B')return 2;
	if(ch=='C')return 3;
	if(ch=='D')return 5;
	if(ch=='F')return 6;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>a>>b>>c>>d;
	ans="0000";
	if(a==c){
		ans[0]='1';
		if(b[0]==d[0]&&b[1]==d[1]){
			ans[1]='1';
			if(check(b[2])==check(d[2])){
				ans[2]='1';
				if(abs(get_val(b[2])-get_val(d[2]))==1){
					ans[3]='1';
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

