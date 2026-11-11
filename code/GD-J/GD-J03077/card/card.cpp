#include <bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 500005
int n,m;
int a[maxn];int ct[maxn];
bool vis[maxn];
int val[4*maxn];
pair<int,int>tag[4*maxn];
void build(int u,int l,int r){
	tag[u]=make_pair(1LL,0LL);
	if(l==r){
		val[u]=ct[l];
		return;
	}
	int mid=(l+r)/2;
	build(u*2,l,mid);
	build(u*2+1,mid+1,r);
	val[u]=val[u*2]+val[u*2+1]; 
} 
void apply(int u,int l,int r,int k,int b){
	val[u]=val[u]*k+b*(r-l+1);
	tag[u]=make_pair(tag[u].first*k,tag[u].second*k+b);
}
void pushdown(int u,int l,int r){
	if(tag[u]==make_pair(1LL,0LL))return;
	int mid=(l+r)/2;
	apply(u*2,l,mid,tag[u].first,tag[u].second);
	apply(u*2+1,mid+1,r,tag[u].first,tag[u].second);
	tag[u]=make_pair(1LL,0LL);
}
void upd(int u,int l,int r,int s,int t,int k,int b){
	if(s<=l&&r<=t){
		apply(u,l,r,k,b);
		return ;
	}
	pushdown(u,l,r);
	int mid=(l+r)/2;
	if(s<=mid) upd(u*2,l,mid,s,t,k,b);
	if(t>mid) upd(u*2+1,mid+1,r,s,t,k,b);
	val[u]=val[u*2]+val[u*2+1];
}
int query(int u,int l,int r,int s,int t){
	if(s<=l&&r<=t)return val[u];
	pushdown(u,l,r);
	int mid=(l+r)/2;
	if(t<=mid)return query(u*2,l,mid,s,t);
	if(s>mid)return query(u*2+1,mid+1,r,s,t);
	return query(u*2,l,mid,s,t)+query(u*2+1,mid+1,r,s,t);
}
int nxt[maxn];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		ct[i]=1;
	}
	map<int,int>mp;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			nxt[j]=0;
		}
		for(int j = i;j <= n;j++){
			ct[j]=1;
		}
		for(int j = i;j <= n;j++){
			if(nxt[a[j]]!=0){
				for(int k=nxt[a[j]];k<j;k++){
					ct[k]=0;
				}
			}
//			cout << nxt[a[j]] << '\n';
			nxt[a[j]]=j;
		}
		for(int j = i;j<=n;j++){
			if(ct[j])mp[a[j]]++;
		}
	}
	for(auto x:mp){
		cout << x.second << " ";
	}
	return 0;
} 
