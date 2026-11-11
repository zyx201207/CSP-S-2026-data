#include<bits/stdc++.h>
using namespace std;
using i64=long long;
using u64=unsigned long long;
using u32=unsigned;
string c[2],s[2];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c[0]>>s[0]>>c[1]>>s[1];
	if(c[0]==c[1]){
		cout<<1;
		if(s[0][0]==s[1][0]&&s[0][1]==s[1][1]){
			cout<<1;
			if((s[0][2]<='C')==(s[1][2]<='C')){
				cout<<1;
				if(abs(int(s[0][2])-int(s[1][2]))==1)cout<<"1\n";
				else cout<<"0\n";
			}else cout<<"00\n";
		}else cout<<"000\n";
	}else cout<<"0000\n";
}