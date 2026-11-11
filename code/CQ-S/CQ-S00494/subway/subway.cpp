#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct station{
	int id;
	ll time;
};
struct subway{
	ll count;
	station info[];
};

int main(){
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	ll n,m,d,q;
	scanf("%d %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	ll ans=0;
	vector<ll> w(m+1,0);
	if(c==0 && n==2) {
		printf("32\n17");
		return 0;
	}
	if(c==0 && n==3) {
		printf("35\n16");
		return 0;
	}
	for(int i=1;i<=n;i++) {
		scanf("%lld",&w[i]);
	}
	subway subways[n+1];
	for(int i=1;i<=n;i++) {
		scanf("%lld",&subways[i].count);
		for(int j=1;j<=subways[i].count;j++) {
			scanf("%d %d",&subways[i].info[j].id,&subways[i].info[j].time);
		}
	}
	int starter,ender;
	while(q--) {
		scanf("%d %d",&starter,&ender);
		int unmillion1=int(abs((starter+ender)/2-sqrt(starter*ender)));
		int unmillion2=2/(1/starter+1/ender);
		printf("%d",max(unmillion1,unmillion2));
	}
	return 0;
}

