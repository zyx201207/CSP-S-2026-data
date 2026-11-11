#include<bits/stdc++.h>
#define int long long
using namespace std;
int x,y,a,b;
char c1,c2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>x>>y>>c1>>a>>b>>c2;
	if(c1>c2) swap(c1,c2);
	if(x==a){
		cout<<1;
		if(b==y){
			cout<<1;
			if((c1=='D'&&c2=='F')||(c2!='D'&&c2!='F')){
				cout<<1;
				if(c1=='A'&&c2=='C') cout<<0;
				else cout<<1;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
