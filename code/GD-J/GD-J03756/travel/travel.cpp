#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Endl "\n",void()
#define endl "\n"
#define End void()
namespace kong{bool st;}
string a,b,c,d;
void solve(){
	cin>>a>>b>>c>>d;
	string x=b,y=d;
	char xx=b.back(),yy=d.back();
	x.pop_back(),y.pop_back();
	if(a!=c) return cout<<"0000",End;
	else if(x!=y) return cout<<"1000",End;
	else if(!((xx>='A'&&xx<='C'&&yy>='A'&&yy<='C')||((xx=='D'&&yy=='F')||(xx=='F'&&yy=='D')))) return cout<<"1100",End;
	else{
		if(xx=='A'&&yy=='B') return cout<<"1111",End;
		else if(xx=='B'&&yy=='C') return cout<<"1111",End;
		else if(xx=='B'&&yy=='A') return cout<<"1111",End;
		else if(xx=='C'&&yy=='B') return cout<<"1111",End;
		else if(xx=='D'&&yy=='F') return cout<<"1111",End;
		else if(xx=='F'&&yy=='D') return cout<<"1111",End;
		else return cout<<"1110",End;
	}
	return;
}
namespace kong{bool ed;double MB(){return abs(&st-&ed)*1.0/1024/1024;}}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int _=1;
//	cin>>_;
	while(_--) solve();
	cerr<<endl<<kong::MB()<<endl;
	return 0; 
} 
