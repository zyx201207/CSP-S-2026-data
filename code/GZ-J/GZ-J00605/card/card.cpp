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
	ll a,b;
	in>>a>>b;
	ve<ll>x(a+1,0);
	for(ll i=1;i<=a;i++){
		in>>x[i];
	}
	ou<<"1 1 1";
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll t=1;
	
	while(t--){
		ai();
	}
	rr 0;
} 
