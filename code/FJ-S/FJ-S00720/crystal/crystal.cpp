#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=5e5+1;
ll n,m;
ll c[MAXN];
ll pre[MAXN];
ll traget=false;

ll cmp(ll x,ll y) {
	return x>y;
}

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >>n>>m;
	int op=m;
	for(int i=1; i<=n; i++) {
		cin >>c[i];
		if(i>=3) {
			if((c[i]+c[i-2])==2*c[i-1]) traget=true;
		}
	}
	if(traget==true) {
		int i=1;
		while(op>=i){
			op-=i;
			i++;
		}
		
    	cout <<i;
		
	} else {
		sort(c+1,c+n+1,cmp);
		int answer=0;

		for(int i=1; i<=n; i++) {
			int ans=1,cnt=0;
			for(int j=i+1; j<=n; j++) {

				if(cnt>=m) break ;
				cnt+=(c[i]-c[j]);
				ans++;
			}
			answer=max(ans,answer);
		}
		cout <<answer<<endl;
	}

	return 0;
}
