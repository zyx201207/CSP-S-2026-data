//GZ-J00605，邱宣然，华东师范大学附属贵阳学校
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ii int
#define bb bool
#define cc char
#define dd double
#define ss string
#define vv void
#define rr return
#define ve vector
#define in cin
#define ou cout
vv ai(){
	ll a;
	ss s="";
	in>>a;
	for(ll i=1;i<=a;i++){
		ll b;
		cc c;
		in>>b>>c;
		for(ll j=1;j<=b;j++){
			s+=c;
		}
	}
	ll l=s.size()/2;
	ll ans=0;
	for(ll i=0,j=s.size()-1;i<l;i++,j--){
		if(s[i]!=s[j]){
			ans++;
		}
	}
	ou<<ans<<endl;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll t=1;
	
	while(t--){
		ai();
	}
	rr 0;
} 
