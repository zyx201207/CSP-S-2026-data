#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else cout<<1;
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"000";
		return 0;
	}
	else cout<<1;
	if((s1[2]<='C'&&s2[2]>='D')||(s2[2]<='C'&&s1[2]>='D')){
		cout<<"00";
		return 0;
	}
	else cout<<1;
	int r=s1[2]-'A'+1;
	int x=s2[2]-'A'+1;
	if(abs(r-x)>1) cout<<0;
	else cout<<1;
	return 0;
}
