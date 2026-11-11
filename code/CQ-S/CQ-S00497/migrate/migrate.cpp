#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,d;
int a[2000005];
struct node{
	int id,l,r;
}P[2000005];
int dl[2000005];
int dr[2000005];
int len=0;
void solve(){
	cin>>n>>d,len=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=2;i<=n-2;i++){
		if(a[i+1]-a[i]>d) continue;
		if(a[i+2]-a[i+1]>d) continue;
		if(a[i]-a[i-1]>d) continue;
		node now;
		now.id=i;
		int p=lower_bound(a+1,a+1+n,a[i+2]-d)-a-1;
		if(p>=i) continue;
		if(a[i+1]-a[p]>d) continue;
		now.l=p;
		if(p<=0 || p>=n+1) continue;
		p=upper_bound(a+1,a+1+n,a[i-1]+d)-a;
		if(p<=i+1) continue;
		if(a[p]-a[i]>d) continue;
		if(p<=0 || p>=n+1) continue;
		now.r=p;
		P[++len]=now;
//		cout<<P[len].l<<' '<<P[len].r<<' '<<P[len].id<<'\n';
	}
//	cout<<'\n';
	dl[1]=1;
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]>d) dl[i]=i;
		else dl[i]=dl[i-1];
	}
	dr[n]=n;
	for(int i=n-1;i>=1;i--){
		if(a[i+1]-a[i]>d) dr[i]=i;
		else dr[i]=dr[i+1];
	}
	int ans=0;
	for(int i=1;i<=len;i++){
		int l,r;
//		if(i!=1){
//			if(P[i].l<P[i-1].r){
//				cout<<7891<<'\n';
//				return;
//			}
//		}
		if(i==1) l=P[i].l-max(dl[P[i].l],1ll)+1;
		else l=P[i].l-max(dl[P[i].l],P[i-1].l+1)+1;
		if(i==len) r=min(n,dr[P[i].r])-P[i].r+1;
		else r=min(P[i+1].r-1,dr[P[i].r])-P[i].r+1;
		l=max(l,1ll);
		r=max(r,1ll);
		ans+=l*r;
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--) solve();
	return 0;
}
/*
0 1
10 3
0 3 6 7 8 9 10 11 14 17

0 1
10 3
0 3 6 7 8 9 10 13 16 19

0 1
8 3
0 1 2 4 8 10 11 13

0 1
5 29418319589926278
-999999999999988021 -999108535769990255 -970581680410061743 -969690216180063977 -969244484065065094
*/
