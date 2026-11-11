#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+9;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000"<<'\n';
		return 0;
	}
	cout<<1;
	string cur1="";
	string cur2="";
	cur1+=b[0];
	cur1+=b[1];
	cur2+=d[0];
	cur2+=d[1];
//	cout<<"$$$   "<<cur1<<' '<<cur2<<"   gksdffhghfh\n";
	if(cur1!=cur2){
		cout<<"000"<<'\n';
		return 0;
	}
	cout<<1;
	if((b[2]<='C'&&d[2]>'C')||(b[2]>'C'&&d[2]<='C')){
		cout<<"00"<<'\n';
		return 0;
	}
	cout<<1;
	char x=b[2],y=d[2];
	if(x>y)swap(x,y);
	if(signed(y)-signed(x)==1&&x!='C'){
		cout<<1<<'\n';
		return 0;
	}
	if(x=='D'&&y=='F'){
		cout<<1<<'\n';
		return 0;
	}
	cout<<0<<'\n';
	return 0;
}
