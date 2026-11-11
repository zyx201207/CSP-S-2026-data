#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string a,b,c,d; int cnt;
#define fre(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
signed main(){
	fre("travel");
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c){
		++cnt,cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]){
			++cnt,cout<<1;
			char p1=b[2],p2=d[2];
			if(p1>p2)swap(p1,p2);
			if(p2<='C'||p1>='D'){
				++cnt,cout<<1;
				if(p2-p1==1)++cnt,cout<<1;
			}
		}
	}
	for(;cnt<4;++cnt)cout<<0;
	return 0;
}
