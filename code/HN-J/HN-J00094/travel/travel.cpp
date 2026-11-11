#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	char e,f;
	cin>>a>>b>>e>>c>>d>>f;
	if(a==c){
		cout<<"1";
		if(b==d){
			cout<<"1";
			if((e>='A' and e<='C' and f>='A' and f<='C') or (e>='D' and e<='F' and f>='D' and f<='F')){
				cout<<"1";
				if(char(e+1)==f or char(e-1)==f)cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
