#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e5 + 7;
bool sur[N];int lst[N],a[N],t[N],ans[N];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		t[i] = lst[a[i]];
		lst[a[i]] = i;
	}
	for(int i=1;i<=n;i++){
		memset(sur,0,sizeof sur);
		for(int j=i;j<=n;j++){
			sur[j] = true;
			if(sur[t[j]]) for(int k=t[j];k<j;k++)sur[k] = false;
		}
		for(int j=i;j<=n;j++)
			if(sur[j])ans[a[j]]++;
	}
	for(int i=1;i<=m;i++)cout << ans[i] << " ";
	return 0;
}

//const int N = 5e5 + 7;
//int lst[N],tim[N],n,m,a[N];int ans[N];
//int fa[N];
//
//struct seg{
//	int l,r;
//}s[N];
//int cnt = 0;
//
//bool cmp(seg a,seg b){
//	if(a.l != b.l)return a.l > b.l;
//	return a.r > b.r;
//}
//
//int getf(int x){
//	if(fa[x] == x)return x;
//	return fa[x] = getf(fa[x]);
//}
////remove:fa[x] = x+1;
//void rem(int time,int l,int r){
//	int now = getf(l);
//	while(now <= r){
//		tim[now] = time;
//		cerr << now << " ";
//		fa[now] = getf(now + 1);
//		now = getf(now);
//	}
//	cerr << "\n";
//}
//
//int main(){
//	ios::sync_with_stdio(0);cin.tie(0);
//	int _ = 1;//cin >> _;
//	while(_--){
//		cin >> n >> m;
//		for(int i=1;i<=n;i++){
//			cin >> a[i];
//			if(lst[a[i]])s[++cnt].l = lst[a[i]],s[cnt].r = i-1;
//			lst[a[i]] = i;
//		}
//		sort(s+1,s+1+cnt,cmp);
////		for(int i=1;i<=cnt;i++){
////			cerr << s[i].l << " " << s[i].r << "\n";
////		}
//		for(int i=1;i<=n+1;i++)fa[i] = i;
//		int nowp = 1;
//		for(int t=n;t>0;t--){
//			while(nowp <= n && s[nowp].l >= t){
//				rem(t,s[nowp].l,s[nowp].r);nowp++;
//			}
//		}
//		for(int i=1;i<=n;i++)cerr << tim[i] << " ";
//		for(int i=1;i<=n;i++){
//			//cerr << tim[i] << " ";
//			ans[a[i]] = ans[a[i]] + (i - tim[i]);
//		} 
////		cerr << "\n";
//		for(int i=1;i<=m;i++)cout << ans[i] << " ";
//	}
//	return 0;
//}

