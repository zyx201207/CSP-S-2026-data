#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],vmax,vmin=INT_MAX,sum=-1,c[5],maxx;
inline void dfs(int step,int val,int last) {
	if(step==m) {
		maxx=max(maxx,val);
		return ;
	}
	for(int i=last+1;i<=n-m+step+1;i++) {
		dfs(step+1,val&a[i],i);
	}
	return ;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		vmax=max(vmax,a[i]);
		vmin=min(vmin,a[i]);
		if(sum==-1) {
			sum=a[i];
		}
		else {
			sum&=a[i];
		}
	}
	if(m==1) {
		cout<<vmax;
		return 0;
	}
	if(m==n) {
		cout<<sum;
		return 0;
	}
	if(m==2) {
		int maxn=0;
		for(int i=1;i<n;i++) {
			for(int j=i+1;j<=n;j++) {
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
		return 0;
	}
	if(vmax<4) {
		for(int i=1;i<=n;i++) {
			c[a[i]]++;
		}
		if(c[3]>=m) {
			cout<<3;
		}
		else if(c[3]+c[2]>=m) {
			cout<<2;
		}
		else if(c[3]+c[1]>=m) {
			cout<<1;
		}
		else {
			cout<<0;
		}
		return 0;
	}
	if(m==n-1) {
		if(vmin==0) {
			int ccc=0,vvv=a[1];
			if(a[1]==0) {
				int cc=a[2];
				for(int i=3;i<=n;i++) {
					cc&=a[i];
				}
				cout<<cc;
				return 0;
			}
			for(int i=2;i<=n;i++) {
				if(ccc==0&&a[i]==0) {
					ccc=1;
					continue;
				}
				vvv&=a[i];
			}
			cout<<vvv;
			return 0;
		}
		int maxn=0;
		for(int i=2;i<=n;i++) {
			int sum=a[1];
			for(int j=1;j<=n;j++) {
				if(i==j) {
					continue;
				}
				sum&=a[j];
			}
			maxn=max(maxn,sum);
		}
		int sum=a[2];
		for(int i=3;i<=n;i++) {
			sum&=a[i];
		}
		cout<<max(maxn,sum);
		return 0;
	}
	if(n>2000) {
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}
	for(int i=1;i<=n-m+1;i++) {
		dfs(1,a[i],i);
	}
	cout<<maxx;
	return 0;
}
