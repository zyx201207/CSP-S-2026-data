#include<bits/stdc++.h>
using namespace std;

int c;

namespace SubA {
	int T;
	int n,k;
	void solve() {
		scanf("%d",&T);
		while(T--) {
			scanf("%d%d",&n,&k);
			if(k==n) puts("0");
			int m=(n-1)/2;
			if(k>=m) puts("1");
			int t=m-k;
			if(t%4==0) t/=4;
			else {
				if(t%4==1) t=t/4+2;
				if(t%4==2) t=t/4+2;
				if(t%4==3) t=t/4+2;
			}
			printf("%d\n",t);
		}
	}
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d",&c);
	if(c==13||c==14) SubA::solve();
	return 0;
}
