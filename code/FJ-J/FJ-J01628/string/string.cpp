#include <bits/stdc++.h>
using namespace std;
int n;
pair <int,char> p[200005];
long long len;
long long ans;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d %c",&p[i].first,&p[i].second);
		len+=p[i].first;
	}
	int qian=1,hou=n;
	while(qian < hou ) {
		if(p[qian].second == p[hou].second) {
			if(p[qian].first ==p[hou].first) {
				qian++;
				hou--;
				continue;
			}
			if(p[qian].first < p[hou].first) {
				p[hou].first-=p[qian].first;
				qian++;
				continue;
			}
			if(p[qian].first > p[hou].first ) {
				p[qian].first-=p[hou].first;
				hou--;
				continue;
			}
		}
		if(p[qian].second!=p[hou].second) {
			if(p[qian].first ==p[hou].first) {
				ans+=p[qian].first;
				qian++;
				hou--;
				continue;
			}
			if(p[qian].first < p[hou].first) {
				p[hou].first-=p[qian].first;
				ans+=p[qian].first;
				qian++;
				continue;
			}
			if(p[qian].first > p[hou].first ) {
				p[qian].first-=p[hou].first;
				ans+=p[hou].first;
				hou--;
				continue;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
