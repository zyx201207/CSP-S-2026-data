#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long 
#define int128 __int128
#define gc getchar()
using namespace std;
const int N=5e5+10;
int rd(){
	int x=0,f=1;char c=gc;
	for(;!isdigit(c);c=gc)if(c=='-')f=-1;
	for(;isdigit(c);x=x*10+c-'0',c=gc);
	return x*f;
}
ll rdll(){
	ll x=0,f=1;char c=gc;
	for(;!isdigit(c);c=gc)if(c=='-')f=-1;
	for(;isdigit(c);x=x*10+c-'0',c=gc);
	return x*f;
}
int n;
ll m,a[N],sum[N];
struct SegTree{
	struct Tree{ll sum,tag;}tr[N*4];
	void push_up(int id){
		tr[id].sum=tr[id<<1].sum+tr[id<<1|1].sum;
	}
	void push_down(int id,int L,int R){
		if(tr[id].tag){
			int mid=(L+R)>>1;
			tr[id<<1].tag+=tr[id].tag;
			tr[id<<1|1].tag+=tr[id].tag;
			tr[id<<1].sum+=(mid-L+1)*tr[id].tag;
			tr[id<<1|1].sum+=(R-mid)*tr[id].tag;
			tr[id].tag=0;
		}
	}
	void update(int l,int r,int L,int R,ll val,int id){
		if(l<=L&&r>=R){
			tr[id].sum+=(R-L+1)*val;
			tr[id].tag+=val;
			return;
		}
		push_down(id,L,R);
		int mid=(L+R)>>1;
		if(l<=mid)update(l,r,L,mid,val,id<<1);
		if(r>=mid+1)update(l,r,mid+1,R,val,id<<1|1);
		push_up(id);
	}
	ll query(int l,int r,int L,int R,int id){
		if(l<=L&&r>=R)return tr[id].sum;
		push_down(id,L,R);
		int mid=(L+R)>>1;ll ans=0;
		if(l<=mid)ans+=query(l,r,L,mid,id<<1);
		if(r>=mid+1)ans+=query(l,r,mid+1,R,id<<1|1);
		return ans;
	}
}seg;
ll t[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=rd();m=rdll();
	for(int i=1;i<=n;i++)a[i]=rdll();
	sort(a+1,a+1+n);
	int l=1,ans=1;
	for(int i=2;i<=n;i++){
		ll add=(a[i]-a[i-1]);
		seg.update(l,i-1,1,n,add,1);
		if(seg.query(l,i,1,n,1)<=m){
			ans=max(ans,(i-l+1));
		}else{
			while(seg.query(l,i,1,n,1)>m)l++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
//wo xiang shang mi huo xing wei da shang
//guan zhu luogu uid 1397333 xie xie qwq 
//guan zhu wo de xue zhang luogu keep_on xie xie qwq
//da wan zhe chang jiu AFO le 
//kong bei qie

//wo qu le
//mei tiao chu T2
//wan dan le
//zen me yao jie shu le
//goodbye OI 
//wait for me , I will go back.
