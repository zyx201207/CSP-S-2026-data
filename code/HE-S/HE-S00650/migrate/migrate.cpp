#include<bits/stdc++.h>
using namespace std;
int n,t[8000006];
long long d,a[2000006],cnt[8000006],ans;
void build(int id,int l,int r){
	t[id]=1e9;
	cnt[id]=0;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
}
void pushup(int id){
	t[id]=t[id<<1];
	cnt[id]=cnt[id<<1];
	if(t[id<<1]==t[id<<1|1]) cnt[id]+=cnt[id<<1|1];
}
void add(int id,int l,int r,int x,int k1,long long k2){
	if(l==r){
		t[id]=k1;
		cnt[id]=k2;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid) add(id<<1,l,mid,x,k1,k2);
	else add(id<<1|1,mid+1,r,x,k1,k2);
	pushup(id);
}
pair<long long,int> get(int id,int l,int r,int x,int y){
	if(x<=l&&y>=r) return make_pair(cnt[id],t[id]);
	int mid=(l+r)>>1;
	pair<long long,int> rst={1e15,1e9};
	if(x<=mid) rst=get(id<<1,l,mid,x,y);
	if(mid<y){
		pair<long long,int> res=get(id<<1|1,mid+1,r,x,y);
		if(rst.second==res.second) rst.first+=res.first;
		else if(rst.second>res.second) rst=res;
	}
	return rst;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;++i) cin>>a[i];
		for(int i=1;i<n;++i){
			build(1,i,n);
			add(1,i,n,i,0,1);
			for(int j=i+1,k=i;j<=n;++j){
				while(k<j&&a[k]<a[j]-d) k++;
				if(k<j){
					pair<long long,int> rst=get(1,i,n,k,j-1);
					add(1,i,n,j,rst.second+1,rst.first);
				}
				else add(1,i,n,j,1e9,0);
				pair<long long,int> rst=get(1,i,n,j,j);
				if(rst.second<1e9&&rst.first==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
