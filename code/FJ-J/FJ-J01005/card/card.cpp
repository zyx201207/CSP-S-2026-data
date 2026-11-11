#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;

struct node{
	int w,id;
	bool operator<(const node&W)const{
		return w<W.w;
	}
};

struct node2{
	int l,r;
	bool operator<(const node2&W)const{
		if(l==W.l) return r<W.r;
		return l<W.l;
	}
};

int n,m;
int a[N],pre_id[N],al[N],re_id[N],t[N],ans[N],vis[N];
priority_queue<node> q;
vector<node2> v[N];
vector<node2> v1;
vector<node2> v2;

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		if(a[i]==2) cout<<i<<" ";
		re_id[a[i]]=i;
	}
//	cout<<"\n";
	
//	for(int i=1;i<=m;i++){
//		cout<<re_id[i]<<" ";
//	}
//	cout<<"\n";
	
	int pow=1;
	for(int i=1;i<=n;i++){
		while(q.size()&&q.top().id<=i){
			vis[t[a[q.top().w]]]=0,pow=min(pow,t[a[q.top().w]]);
			q.pop();
		}
		if(q.size()){
			al[i]=pre_id[a[q.top().w]];
//			if(t[a[q.top().w]]==0) t[a[q.top().w]]=1;
//			if(t[a[i]]==0)t[a[i]]=-t[a[q.top().w]];
		}
		while(vis[pow]) pow++;
		if(t[a[i]]==0){
			t[a[i]]=pow;
			vis[pow]=1;
		} 
		pre_id[a[i]]=i;
		q.push({i,re_id[a[i]]});
		v[t[a[i]]].push_back({al[i],i});
//		cout<<a[i]<<" "<<i<<" "<<re_id[a[i]]<<" "<<al[i]<<"\n";
//		cout<<a[i]<<" "<<al[i]<<" "<<i<<"\n";
	}
	
//	sort(v1.begin(),v1.end());
//	int sum=0,ll=v1[0].l,rr=v1[0].r;
//	for(int j=0;j<v1.size();j++){
//		if(rr<v1[j].l){
//			sum+=rr-ll;
//			ll=v1[j].l,rr=v1[j].r;
//		}
//		if(v1[j].r==re_id[a[v1[j].r]]) ans[a[v1[j].r]]=sum+v1[j].r-ll;
//		rr=max(rr,v1[j].r);
//	}
//	
//	sort(v2.begin(),v2.end());
//	sum=0,ll=v2[0].l,rr=v2[0].r;
//	for(int j=0;j<v2.size();j++){
//		if(rr<v2[j].l){
//			sum+=rr-ll;
//			ll=v2[j].l,rr=v2[j].r;
//		}
//		if(v2[j].r==re_id[a[v2[j].r]]) ans[a[v2[j].r]]=sum+v2[j].r-ll;
//		rr=max(rr,v2[j].r);
//	}
	
	for(int i=1;i<=m;i++){
//		cout<<t[i]<<" "<<v[t[i]].size()<<"\n";
		sort(v[t[i]].begin(),v[t[i]].end());
		int ll=v[t[i]][0].l,rr=v[t[i]][0].r;
		for(int j=0;j<v[t[i]].size();j++){
//			cout<<v[t[i]][j].l<<" "<<v[t[i]][j].r<<"\n";
			if(rr<v[t[i]][j].l){
				ans[i]+=rr-ll;
				ll=v[t[i]][j].l,rr=v[t[i]][j].r;
			}
			rr=max(rr,v[t[i]][j].r);
			if(rr>=re_id[i]){
				rr=re_id[i];
				break;
			} 
		}
		ans[i]+=rr-ll;
		cout<<ans[i]<<" ";
	}
}

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios_base::sync_with_stdio(0),cin.tie(0);
	int TTT=1;
//	cin>>TTT;
	while(TTT--){
		solve();
	}
}