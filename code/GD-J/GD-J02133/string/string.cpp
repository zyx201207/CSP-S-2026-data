#include<bits/stdc++.h>
using namespace std;
deque<pair<long long,char> > q;
long long a[200005];
char c[200005];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) {
	    long long x;
	    char y;
	    cin>>x>>y;
	    if(q.empty()) q.push_back({x,y});
	    else{
	    	auto p=q.back();
	    	if(p.second==y) {
	    		q.pop_back();
	    		q.push_back({x+p.first,y});
			}
			else{
				q.push_back({x,y});
			}
		}
	}
	int t=0;
	while(!q.empty()) {
		t++;
		auto p=q.front();
		a[t]=p.first;
		c[t]=p.second;
		q.pop_front();
	}
	int l=1,r=t;
	long long ans=0;
	while(l<=r) {
		if(c[l]!=c[r]||a[l]!=a[r]) {
			ans+=min(a[l+1],a[r-1]);
		}
		l++,r--;
	}
	cout<<ans;
	return 0;
}
