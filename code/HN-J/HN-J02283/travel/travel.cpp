#include<bits/stdc++.h>
#define int long long
using namespace std;
string r1,r2,r3,x1,x2,x3;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>r1>>r2>>x1>>x2;
	if(r1==x1){
		cout<<1;
		int n=0,m=0;
		n=(r2[0]-'0')*10+r2[1]-'0';
		m=(x2[0]-'0')*10+x2[1]-'0';
		if(n==m){
			cout<<1;
			int u=0,v=0;
			if(r2[2]<'D'){
				u=1;
			}
			if(x2[2]<'D'){
				v=1;
			}
			if(u==v){
				cout<<1;
				u=r2[2]-'A';
				v=x2[2]-'A';
				if(v<u) swap(u,v);
				if(v-u==1 && v!=4 && u!=4){
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

