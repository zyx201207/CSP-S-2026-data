#include<bits/stdc++.h>
#define rep(i,n,m) for(int i(n);i<=(m);++i)
#define rev(i,n,m) for(int i(n);i>=(m);--i)
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int a,b;
	string c,d;
	cin>>a>>c>>b>>d;
	string rowa=c.substr(0,2),rowb=d.substr(0,2);
	char cola=c[2],colb=d[2];
	if(a==b){
		cout<<"1";
		if(rowa==rowb){
			cout<<"1";
			if(cola>colb) swap(cola,colb);
			if(colb<='C'||cola>='D'){
				cout<<"1";
				if(colb==cola+1) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
