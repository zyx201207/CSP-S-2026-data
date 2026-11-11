#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+5;
ll n,a[N],ans;
char c[N];
struct M{
	ll pos,len;
};
M sett(ll p,ll l){
	M ret;
	ret.pos=p,ret.len=l;
	return ret;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	M l,r;
	l=sett(1,1);
	r=sett(n,a[n]);
	while(true){
		if(l.pos>=r.pos)break;
		ll lrem=a[l.pos]-l.len+1;
		ll rrem=r.len;
		if(lrem<rrem){
			if(c[l.pos]!=c[r.pos])ans+=lrem;
			l.pos++;l.len=1;
			r.len-=lrem;
		}
		else{
			if(c[l.pos]!=c[r.pos])ans+=rrem;
			r.pos--;r.len=a[r.pos];
			if(lrem!=rrem)l.len+=rrem;
			else{l.pos++,l.len=1;}
		}
	}
	cout<<ans;
	return 0;
}
//9:30-10:15
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
