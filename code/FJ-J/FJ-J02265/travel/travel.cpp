#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	bool f1=(c1==c2);
	bool f2=(f1&&s1[0]==s2[0]&&s1[1]==s2[1]);
	bool f3=(f2&&(s1[2]<='C'&&s2[2]<='C')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'));
	bool f4=f3&&abs((int)(s1[2]-s2[2]))==1;
	if(f1){
		cout<<1;
	}else{
		cout<<0;
	}
	if(f2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(f3){
		cout<<1;
	}else{
		cout<<0;
	}
	if(f4){
		cout<<1;
	}else{
		cout<<0;
	}
	return;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int T=1;
	while(T--)solve();
	return 0;
}
