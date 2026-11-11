#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int n,m,a[500010],pos[300010],tr[500010],ans[300010];
bool del[500010];
int lowbit(int x) {
	return x&-x;
}
void update(int x,int v) {
	while(x<=n) {
		tr[x]+=v;
		x+=lowbit(x);
	}
	return;
}
int query(int x) {
	int res=0;
	while(x) {
		res+=tr[x];
		x-=lowbit(x);
	}
	return res;
}
bool checka() {
	for(int i=2; i<=n; i++) {
		if(a[i-1]>a[i]) {
			return false;
		}
	}
	return true;
}
signed main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(checka()) {
		a[n+1]=1000000000000;
		for(int i=1; i<=n; i++) {
			if(a[i]<a[i+1]) {
				ans[a[i]]=i;
			}
		}
		for(int i=1; i<=m; i++) {
			cout<<ans[i]<<" ";
		}
		return 0;
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			pos[j]=0;
		}
		for(int j=i; j<=n; j++) {
			del[j]=false;
		}
		for(int j=i; j<=n; j++) {
			if(pos[a[j]]==0) {
				pos[a[j]]=j;
			} else {
				for(int k=pos[a[j]]; k<j; k++) {
					del[k]=true;
				}
				for(int k=1; k<=m; k++) {
					pos[k]=0;
				} 
				for(int k=i; k<=j; k++) {
					if(del[k]==false) {
						pos[a[k]]=k;
					}
				}
			}
		}
		for(int j=i; j<=n; j++) {
			if(del[j]==false) {
				ans[a[j]]++;
			}
		}
	}
	for(int i=1; i<=m; i++) {
		cout<<ans[i]<<" ";
	}
	return 0;
}
