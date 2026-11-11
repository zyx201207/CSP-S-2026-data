#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=5e5+10;
int sum[N],f[N];
int maxn;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>f[i];
	}
	sort(f+1,f+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+f[i];
	}
	int last=1;
	for(int i=1;i<=n;i++){
		int k=(i-last)*f[i]-sum[i-1]+sum[last-1];
		while(last+1<=i&&k>m){
			last++;
			k=(i-last)*f[i]-sum[i-1]+sum[last-1];
		}
		if(k<=m){
			maxn=max(maxn,i-last+1);
		}
	}
	cout<<maxn;
	return 0;
}

