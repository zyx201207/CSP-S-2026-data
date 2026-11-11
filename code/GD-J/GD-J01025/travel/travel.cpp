#include<bits/stdc++.h>
#define int long long 
using namespace std;
int c1,s1,c2,s2,k1,k2;
void solve(){
	string c,cc,s,ss;
	cin>>c>>s>>cc>>ss;
	c1=(c[0]-'0')*10+(c[1]-'0');
	c2=(cc[0]-'0')*10+(cc[1]-'0');
	s1=(s[0]-'0')*10+(s[1]-'0');
	s2=(ss[0]-'0')*10+(ss[1]-'0');
	k1=(s[2]-'A');
	k2=(ss[2]-'A');
	if(c1==c2){
		cout<<1;
		if(s1==s2){
			cout<<1;
			if((k1<3&&k2<3)||(k1>=3&&k2>=3)){
				cout<<1;
				if(k1==k2+1||k2==k1+1){
					cout<<1;
				}else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int _=1;
	//cin>>_;
	for(int i=1;i<=_;i++){
		solve();
	}
	return 0;
}
