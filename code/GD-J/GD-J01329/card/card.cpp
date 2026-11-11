#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=5*1e5+3,M=3*1e5+3;

int n,m;
int a[N];
int pos[M];
int cnt[N];
int ans[M];
int f[N][20];

signed main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		cnt[a[i]]++;
		if(!pos[a[i]]) pos[a[i]]=i;
		else {
			f[pos[a[i]]][0]=i;
			pos[a[i]]=i;
		}
	}
	
	for(int i=n;i>=1;i--) {
		if(f[i][0]) cnt[i]=i;
		else cnt[i]=cnt[i+1];
	}
	
	for(int i=1;i<20;i++) {
		for(int j=1;j<=n;j++) {
			f[j][i]=f[f[j][i-1]][i-1];
		}
	}
	
	for(int i=1;i<=n;i++) {
		int last=i,p=cnt[i];
		while(p) {
			for(int j=last;j<p;j++) {
				ans[a[j]]++;
			}
			for(int j=19;j>=0;j--) {
				if(f[p][j]) {
					p=f[p][j];
				}
			}
			last=p;
			p=cnt[p];
		}
		for(int j=last;j<=n;j++) ans[a[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
}
