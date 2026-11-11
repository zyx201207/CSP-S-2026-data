#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],h,t,ans[300005];
struct Node {
	int nxid,prid;
}g[500005];
void f(int now,int x) {
//	/*DEBUG*/cout<<"f";
	if(now==t) return;
	if(a[now]==a[x]) {
		g[g[now].prid].nxid=x;
		g[x].prid=g[now].prid;
		return;
	}
	f(g[now].nxid,x);
}
void count(int now) {
//	/*DEBUG*/cout<<a[now]<<" ";
	ans[a[now]]++;
	if(now==t) {
		return;
	}
	count(g[now].nxid);
}
int main() {
	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
//	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for(int i=1;i<=n;i++) {//ÂÖÊý 
//		g[i].nxid=i+1;
//		g[i].prid=-1;
//		g[n].nxid=n+1;
//		g[n].prid=n-1;
		h=0;t=0;
//		for(int j=i+1;j<n;j++) {
//			g[j].nxid=j+1;
//			g[j].prid=j-1;
//		}
		for(int j=i;j<=n;j++) {//ÒÀ´Î³öÅÆ
			g[j].prid=t;
			g[t].nxid=j;
			t=j;
			f(h,j);
		}
		count(h);
//		/*DEBUG*/cout<<"i="<<i<<"\n";
	}
	for(int i=1;i<=m;i++) {
		cout<<ans[i]<<" ";
	}
	return 0;
}
