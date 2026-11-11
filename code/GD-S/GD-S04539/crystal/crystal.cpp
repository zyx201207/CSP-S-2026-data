#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
long long n,m,f[N],tot,ans,ansi;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>f[i];
	sort(f+1,f+n+1);
	for(long long k=1;k<=n;k++) {
		while(f[k-1]==f[k]&&k<=n) k++;
		if(n-k+1<=ans) break;
		bool fg=true;
		tot=0;
		for(long long i=k;i<n&&fg;i++) {
			tot+=(f[i+1]-f[i])*(i-k+1);
			if(tot==m) {
				for(int j=i+1;j<=n;j++) {
					if(f[i+1]!=f[j]) {
						if(ans<j-k) ans=j-k,ansi=k;
						fg=false;
						break;
					}
				}
			} else if(tot>m) {
				if(ans<i-k+1) ans=i-k+1,ansi=k;
				fg=false;
			}
		}
	}
	for(long long k=ansi;k<=n;k++) {
		bool fg=true;
		tot=0;
		for(long long i=k;i<n&&fg;i++) {
			tot+=(f[i+1]-f[i])*(i-k+1);
			if(tot==m) {
				for(int j=i+1;j<=n;j++) {
					if(f[i+1]!=f[j]) {
						if(ans<j-k) ans=j-k;
						fg=false;
						break;
					}
				}
			} else if(tot>m) {
				if(ans<i-k+1) ans=i-k+1;
				fg=false;
			}
		}
		if(f[k+1]!=f[k]) break;
	}
	cout<<ans;
	return 0;
}
