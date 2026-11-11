#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int c,t;
int land[MAXN];
int Distance[MAXN];
int ans[MAXN];

void fly(int l[],int dis[],int d,int n,int t0) {
//	bool traget=false;
	int landsu=0;
	int disum=0;
	for(int i=1; i<n; i++) {
		disum+=dis[i];
		landsu++;
		if(disum<=d) continue ;
		else if(disum>d) {
			if(disum%d==0 && (landsu-1)==disum/d && (landsu+1)!=n) {
				ans[t0]++;
//				if(disum==Sum0) traget=true;
			} else if(disum%d!=0 && (landsu-1)==disum/d+1 && (landsu+1)!=n) {
				ans[t0]++;
//				if(disum==Sum0) traget=true;
			}
		}
	}
	landsu=0;
	disum=0;
	for(int i=n-1; i>=1; i--) {
		disum+=dis[i];
		landsu++;
		if(disum<=d) continue;
		else if(disum>d) {
			if(disum%d==0 && (landsu-1)==disum/d) {
				ans[t0]++;
			} else if(disum%d!=0 && (landsu-1)==disum/d+1) {
				ans[t0]++;
			}
		}
	}
//	if(traget==true) ans[t0]--;
}

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(Distance,0,sizeof(Distance));
	cin >>c>>t;
	int op=t;
	while(t--) {
		int n0,d0;
		cin >>n0>>d0;
//		int Sum=0;
		for(int i=1; i<=n0; i++) {
			cin >>land[i];
			if(i>1) {
				Distance[i-1]=land[i]-land[i-1];
			}
//			Sum+=Distance[i];
		}
		fly(land,Distance,d0,n0,t);
	}
	for(int i=op-1; i>=0; i--) {
		cout <<ans[i]<<endl;
	}
	return 0;
}
