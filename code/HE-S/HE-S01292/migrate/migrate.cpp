#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int N=310;
int c,T,n,d,a[N],nxt[N],pre[N],flag;
bool vis[N][N];
vector<int>L,R;
bool check(int x,int y) {
	R.clear(),L.clear();
	int pos=x;
	while(pos<=y) {
		if(pos==flag) {
			if(nxt[pos-1]==pos) return 0;
			pos--;
		}
		R.pb(pos);
		if(pos==nxt[pos]||pos==y) break;
		pos=nxt[pos];
		if(pos>y) R.pb(y);
	}
	pos=y;
	while(pos>=x) {
		if(pos==flag) {
			if(pre[pos+1]==pos) return 0;;
			pos++;
		}
		L.pb(pos);
		if(pos==pre[pos]||pos==x) break;
		pos=pre[pos];
		if(pos<x) L.pb(x);
	}
	if(L.size()!=R.size()) return 0;
	reverse(L.begin(),L.end());
	for(int i=0;i<(int)L.size();i++) if(L[i]!=R[i]) return 0;
	return 1;
}
signed main() {
	freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
//	freopen("migrate3.in","r",stdin),freopen("data.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>T; while(T--) {
		flag=0;
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) {
			int l=i,r=n,res=i;
			while(l<=r) {
				int mid=(l+r)>>1;
				if(a[mid]-a[i]<=d) res=mid,l=mid+1;
				else r=mid-1;
			}
			nxt[i]=res;
		}
		for(int i=1;i<=n;i++) {
			int l=1,r=i,res=i;
			while(l<=r) {
				int mid=(l+r)>>1;
				if(a[i]-a[mid]<=d) res=mid,r=mid-1;
				else l=mid+1;
			}
			pre[i]=res;
		}
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) {
			vis[i][j]=0;
			if(a[j]-a[i]<=d||check(i,j)) vis[i][j]=1;
		} 
		for(flag=1;flag<=n;flag++) {
			for(int i=1;i<flag;i++) for(int j=flag+1;j<=n;j++) {
				if(vis[i][j]||i==flag||j==flag) continue;
				if(check(i,j)) ans++; 
			}
		}
		cout<<ans/2<<"\n";
	}
	return 0;
}
