#include<bits/stdc++.h>
namespace zcy{
	using namespace std;
	typedef long long ll;
	typedef pair<int,int> pii;
	typedef pair<ll,ll> pll;
	const int MAXN=5e5+12;
	
	ll n,m;
	ll a[MAXN];
	
	class SegmentTree{
		struct node{
			int l,r;
			ll tag;
			ll sum;
		}t[MAXN*4];
		
		inline ll len(int sp){
			return t[sp].r-t[sp].l+1;
		}
		
		void pushup(int sp){
			t[sp].sum=t[sp<<1].sum+t[sp<<1|1].sum;
		}
		
		void pushdown(int sp){
			t[sp<<1].sum+=len(sp<<1)*t[sp].tag;
			t[sp<<1|1].sum+=len(sp<<1|1)*t[sp].tag;
			t[sp<<1].tag+=t[sp].tag;
			t[sp<<1|1].tag+=t[sp].tag;
			t[sp].tag=0;
		}
		
		void _init(int l,int r,int sp){
			t[sp]={l,r,0,0};
			if(l==r)return;
			int mid=(l+r)>>1;
			_init(l,mid,sp<<1);
			_init(mid+1,r,sp<<1|1);
		}
		
		void _update(int l,int r,ll k,int sp){
			if(l<=t[sp].l&&t[sp].r<=r){
				t[sp].sum+=len(sp)*k;
				t[sp].tag+=k;
				return;
			}
			int mid=(t[sp].l+t[sp].r)>>1;
			if(l<=mid)_update(l,r,k,sp<<1);
			if(r>mid)_update(l,r,k,sp<<1|1);
			pushup(sp);
		}
		
		ll _query(int l,int r,int sp){
			if(l<=t[sp].l&&t[sp].r<=r){
				return t[sp].sum;
			}
			int mid=(t[sp].l+t[sp].r)>>1;
			ll sum=0;
			pushdown(sp);
			if(l<=mid)sum+=_query(l,r,sp<<1);
			if(r>mid)sum+=_query(l,r,sp<<1|1);
			pushup(sp);
			return sum;
		}
		
		public:
		
		void init(){
			_init(1,n,1);
		}
		
		void update(int l,int r,ll k){
			_update(l,r,k,1);
		}
		ll query(int l,int r){
			return _query(l,r,1);
		}
	}sg;
	
	int main(){
		#ifndef DEBUG
		freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);
		ios::sync_with_stdio(0);
		cin.tie(0);
		#endif
		
		cin>>n>>m;
		sg.init();
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+1+n);
		
		//依次尝试拢到i所在高度 
		a[0]=LLONG_MIN;
		int ans=1;
		int l=1;
		for(int i=2;i<=n;i++){
			sg.update(1,i-1,a[i]-a[i-1]);
			while(sg.query(l,i-1)>m)l++;
			ans=max(ans,i-l+1);
		}
		cout<<ans<<"\n";

		return 0;
	}
}
int main(){
	zcy::main();
	return 0;
}

