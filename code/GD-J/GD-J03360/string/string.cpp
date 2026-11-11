#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
struct s{
	ll l;
	char c;
}a[N],le,ri;
ll ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i].l>>a[i].c;
	}
	ll ln=1,rn=n;
	le=a[1];
	ri=a[n];
	while(ln<rn){
		if(le.l<=ri.l){
			if(le.c!=ri.c)
			ans+=le.l;
			ri.l-=le.l;
			if(ri.l==0){
				rn--;
				ri=a[rn];
			}
			ln++;
			le=a[ln];
		}
		else{
			if(le.c!=ri.c)
			ans+=ri.l;
			le.l-=ri.l;
			if(le.l==0){
				ln++;
				le=a[ln];
			}
			rn--;
			ri=a[rn];
		}
	}
	cout<<ans;
	return 0;
}
