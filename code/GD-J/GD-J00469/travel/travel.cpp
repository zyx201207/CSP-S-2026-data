#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define rep(x,y,z) for(int x=y;x<=z;++x)
#define per(x,y,z) for(int x=y;x>=z;--x)
#define endl '\n'
typedef long long ll;
string s1,s2,s3,s4;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3){
		cout<<"0000"<<endl;
		return 0;
	}
	else cout<<1;
	if(s2[0]!=s4[0]||s2[1]!=s4[1]){
		cout<<"000"<<endl;
		return 0;
	}
	else cout<<1;
	if((s2[2]>='D'&&s4[2]>='D')||(s2[2]<='C'&&s4[2]<='C')){
		cout<<1;
		if(abs(int(s2[2])-(int)s4[2])==1)cout<<1<<endl;
		else cout<<0<<endl;
	}
	else cout<<"00"<<endl;
	return 0;
}
