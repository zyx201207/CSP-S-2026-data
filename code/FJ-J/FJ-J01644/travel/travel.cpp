#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,ans;
int xa,ya,za,xb,yb,zb;
void solve(){
	ans="0000";
	cin>>a>>b>>c>>d;
	for(int i=0;i<a.length();i++){
		xa*=10,xa+=(a[i]-'0');
	}
	for(int i=0;i<b.length()-1;i++){
		ya*=10,ya+=(b[i]-'0');
	}
	za=min(b[b.length()-1]-'A',4);
	for(int i=0;i<c.length();i++){
		xb*=10,xb+=(c[i]-'0');
	}
	for(int i=0;i<d.length()-1;i++){
		yb*=10,yb+=(d[i]-'0');
	}
	zb=min(d[d.length()-1]-'A',4);
	if(xa==xb){
		ans[0]='1';
		if(ya==yb){
			ans[1]='1';
			if(za<3&&zb<3||za>2&&zb>2){
				ans[2]='1';
				if(za-zb==1||zb-za==1){
					ans[3]='1';
				}
			}
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}
