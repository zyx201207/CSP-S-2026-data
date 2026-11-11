#include<bits/stdc++.h>
using namespace std;

void solve(){
	string rc,rs,xc,xs,dn="0000";
	cin>>rc>>rs>>xc>>xs;
	if(rc==xc){
		dn[0]='1';
		if(rs[0]==xs[0]&&rs[1]==xs[1]){
			dn[1]='1';
			char r=rs[2],x=xs[2];
			if((r<='C'&&x<='C')||(r>='D'&&x>='D')){
				dn[2]='1';
				if(r-x==1||r-x==-1){
					dn[3]='1';
				}
			}
		}
	} 
	cout<<dn;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
