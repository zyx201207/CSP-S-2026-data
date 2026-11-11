#include<bits/stdc++.h>
using namespace std;
long long n,m;
vector<long long> a;
long long dfs(long long last,long long idx,long long cnt) {
	if(idx>n&&cnt<=m) return -1;
	if(cnt>m&&idx<=n) return -1;
	if(cnt>m||idx>n) return last;
	if(last==-1) return max(dfs(a[idx],idx+1,cnt+1),dfs(last,idx+1,cnt));
	return max(dfs(last&a[idx],idx+1,cnt+1),dfs(last,idx+1,cnt));
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long tmp=-1e18,tmp2,tmp3;
	cin>>n>>m;
	a.resize(n+1);
	for(long long i=1; i<=n; i++) {
		cin>>a[i];
		if(i==1) tmp2=a[i];
		if(m==1) tmp=max(tmp,a[i]);
		if(m==n) tmp2=tmp2&a[i];
	}
	if(m==1) {
		cout<<tmp<<"\n";
		return 0;
	} else if(m==n) {
		cout<<tmp2<<"\n";
		return 0;
	}
	if(m==2&&n<=2000) {
		for(long long i=1; i<n; i++) {
			for(long long j=i+1; j<=n; j++) tmp3=max(tmp3,a[i]&a[j]);
		}
		cout<<tmp3<<"\n";
		return 0;
	}
	cout<<dfs(-1,1,1)<<"\n";
	return 0;
}

