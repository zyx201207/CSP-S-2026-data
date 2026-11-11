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
ll x[2000000];
bb cmp(ll a,ll b){
	rr a>b;
}
vv ai(){
    ll a,b;
    in>>a>>b;
    for(ll i=1;i<=a;i++){
    	in>>x[i];
	}
	sort(x+1,x+a+1,cmp);
	ll c=x[1];
	for(ll i=1;i<=b;i++){
		c&=x[i];
	}
	ou<<c;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll t=1;
	
	while(t--){
		ai();
	}
	rr 0;
} 
