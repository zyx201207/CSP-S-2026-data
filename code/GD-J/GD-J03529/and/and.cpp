#include<bits/stdc++.h>
#define ll long long
#define fi(x) freopen(x".in","r",stdin)
#define fo(x) freopen(x".out","w",stdout)
#define wc(x) fi(x);fo(x)
#define INF 0x3f3f3f3f
#define F first
#define S second
using namespace std;
const int N=2e5+10;
int n,a[N],ans,m;
vector<int> hav[40];
int main() {
	wc("and");
	/*ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);*/
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		int ls=a[i],l=0;
		while(ls>0) {
			++l;
			if(ls&1) hav[l].push_back(i);
			ls>>=1;
		}
	}
	int mx=32;
	while(mx>0) {
		while(mx>0&&hav[mx].size()<m) {
			mx--;
		}
		if(mx==0) break;
		ans+=(1<<(mx-1));
		for(int i=mx-1; i; i--) hav[i].clear();
		for(auto i:hav[mx]) {
			int ls=a[i]&((1<<(mx-1))-1),l=0;
			while(ls>0) {
				++l;
				if(ls&1) hav[l].push_back(i);
				ls>>=1;
			}
		}
		mx--;
	}
	cout<<ans;
	return 0;
}

