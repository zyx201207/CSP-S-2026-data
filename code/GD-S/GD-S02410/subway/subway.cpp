#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
int w[N],ans=INT_MAX,c,n,m,d,q;
struct node{
	int u,v,x,y;
	bool dis=0;
}a[501];
//struct train{
//	int k,b[N],t[N];
//	bool dis[N];
//}s[501];
void f(int x,int y,int cnt){
	if(x==y){
		ans=min(cnt,ans);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(a[i].u==a[i].v) continue;
		if(a[i].u==x&&!a[i].dis){
			a[i].dis=1;
			f(a[i].v,y,cnt+a[i].x+a[i].y);
			a[i].dis=0;
		}
		if(a[i].v==x&&!a[i].dis){
			a[i].dis=1;
			f(a[i].u,y,cnt+a[i].x+a[i].y);
			a[i].dis=0;
		}
	}
}
//void f1(int x,int y,int cnt){
//	if(x==y){
//		ans=min(cnt,ans);
//		return ;
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=s[i].k;j++){
//			if(s[i].b[j]==x){
//				for(int k=1;k<=s[i].k;k++){
//					if(s[i].b[k]==x||s[i].dis[k]) continue;
//					f(s[i].b[k],y,cnt+s[i].t[k]+s[i].t[x]);
//					s[i].dis[k]=1;
//				}
//				break;
//			}
//		}
//		if(a[i].u==x&&!a[i].dis){
//			a[i].dis=1;
//			
//			a[i].dis=0;
//		}
//		if(a[i].v==x&&!a[i].dis){
//			a[i].dis=1;
//			f(a[i].u,y,cnt+a[i].x+a[i].y);
//			a[i].dis=0;
//		}
//	}
//}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	if(c>=7&&c<=11){
		for(int i=1;i<=m;i++) cin >> w[i];
		for(int i=1;i<=n;i++){
			int op;
			cin >> op;
			if(op==1) cin >> op >> op;
			else cin >> a[i].u >> a[i].x >> a[i].v >> a[i].y;
		}
		while(q--){
			ans=INT_MAX;
			int x,y;
			cin >> x >> y;
			f(x,y,w[x]+w[y]);
			if(ans==INT_MAX) cout << 0 << endl;
			else cout << ans << endl;
		}
	}
//	else{
//		for(int i=1;i<=m;i++) cin >> w[i];
//		for(int i=1;i<=n;i++){
//			cin >> s[i].k;
//			for(int j=1;j<=s[i].k;j++) cin >> s[i].b[j] >> s[i].t[j];
//		}
//		while(q--){
//			ans=INT_MAX;
//			int x,y;
//			cin >> x >> y;
//			f1(x,y,w[x]+w[y]);
//			cout << ans << endl;
//		}
//	}
	return 0;
}
