#include<bits/stdc++.h>//Trick||Treat!
#define int long long
using namespace std;
bitset<30>b[200005];
int n,m;
int a[200005];
int f(int gn,int maxn) {
	if(maxn==-1)return 0;
	for(int i=maxn; i>=0; i--) {
		int cnt=0;
		for(int j=1; j<=gn; j++) {
			if(b[a[j]][i]==1)cnt++;
		}
		if(cnt>=m) {
			int idx=0,add=0;
			for(int j=1; j<=gn; j++) {
				if(b[a[j]][i]==1)a[++idx]=a[j];
			}
			return f(idx,i-1)+(1<<i);
			break;
		}
	}
}
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		int x;
		cin>>x;
		b[i]=x;
		a[i]=i;
	}
	cout<<f(n,30);
	return 0;
}
