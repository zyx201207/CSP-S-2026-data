#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	string a,b,c,d;cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1;
			char p=b[2],q=d[2];
			if(p>q) swap(p,q);
			if(p<='C'&&q<='C'||p>'C'&&q>'C'){
				cout<<1;
				if(q-p==1||p=='D'&&q=='F') cout<<1<<endl;
				else cout<<0<<endl;
			}
			else cout<<"00"<<endl;
		}
		else cout<<"000"<<endl;
	}
	else cout<<"0000"<<endl; 
	return 0;
}
