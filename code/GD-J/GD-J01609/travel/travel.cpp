#include <bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int N=1e6+10;
constexpr ll INF=1e18;
string c1,c2,s1,s2;
int Abs(int x){
	if(x>=0) return x;
	return -x;
}
void solve(){
	cin>>c1>>s1>>c2>>s2;
	string ans="";
	if(c1!=c2){
		ans+="0000";
		cout<<ans;
		return;
	}else if(c1==c2){
		ans+="1";
		string k1="",k2="";
		for(int i=0;i<2;i++){
			k1+=s1[i];
			k2+=s2[i];
		}
		char id1=s1[2],id2=s2[2];
		if(k1==k2){
			ans+="1";
			if((id1<='C' && id2<='C') || (id1>='D' && id2>='D')){
				ans+="1";
				if((id1<='C' && id2<='C' && Abs(id1-id2)==1)){
					ans+="1";
					cout<<ans;
					return;
				}else if((id1>='D' && id2>='D' && Abs(id1-id2)==2)){
					ans+="1";
					cout<<ans;
				}else{
					ans+="0";
					cout<<ans;
				}
			}else{
				ans+="00";
				cout<<ans;
				return; 
			}
		}else{
			ans+="000";
			cout<<ans;
			return;
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	solve();
	return 0;
}

