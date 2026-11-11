#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

namespace solution{
	int n,m;
	int a[500005];
	int lst[500005];
	int pre[500005];
	int ans[500005];
	bool mark[500005];
	priority_queue<int> pq;
	namespace bf{
		stack<int> stk;
		int ans[500005];
		vector<int> pos[500005];
		void solve(){
			for(int i = 1;i<=n;i++){
				for(int j = 1;j<=m;j++) pos[j].clear();
				while(!stk.empty()) stk.pop();
				for(int j = i;j<=n;j++){
					if(!pos[a[j]].empty()){
						while(!stk.empty()){
							int X = stk.top();
							if(X==a[j]) break;
							stk.pop();
							pos[X].pop_back();
						}
					}else stk.push(a[j]),pos[a[j]].push_back(j);
				}
				while(!stk.empty()){
					int X = stk.top();
					stk.pop();
					ans[X]++;
				}
			}
			for(int i = 1;i<=m;i++) cout<<ans[i]<<' ';
		}
	}
	namespace specialA{
		int lst[500005];
		void solve(){
			for(int i = 1;i<=n;i++) lst[a[i]] = i;
			for(int i = 1;i<=m;i++){
				cout<<lst[i]<<' ';
			}
		}
	}
	int maxn[2000005];
	int lazy[2000005];
//	bool mark[2000005];
	void pushdown(int id){
		if(lazy[id]!=0){
			maxn[id*2] = max(maxn[id*2],lazy[id]);
			maxn[id*2+1] = max(maxn[id*2+1],lazy[id]);
			lazy[id*2] = max(lazy[id*2],lazy[id]);
			lazy[id*2+1] = max(lazy[id*2+1],lazy[id]);
			lazy[id] = 0;
		}
		mark[id*2]|=mark[id];
		mark[id*2+1]|=mark[id];
	}
	void fix(int id,int L,int R,int l,int r,int val){
		if(l>r) return ;
		if(L==l&&R==r){
//			cout<<id<<' '<<L<<' '<<R<<endl;
			mark[id] = true;
			maxn[id] = max(maxn[id],val);
			return ;
		}
		pushdown(id);
		int mid = (L+R)>>1;
		if(l<=mid) fix(id*2,L,mid,l,min(mid,r),val);
		if(mid+1<=r) fix(id*2+1,mid+1,R,max(mid+1,l),r,val);
		maxn[id] = max(maxn[id*2],maxn[id*2+1]);
//		mark[id] = mark[id*2]|mark[id*2+1];
	}
	pair<int,bool> query(int id,int L,int R,int pos){
//		if(!mark[id]) return make_pair(pos,false);
		if(L==R) return make_pair(maxn[id],mark[id]);
		pushdown(id);
		int mid = (L+R)>>1;
		if(pos<=mid) return query(id*2,L,mid,pos);
		return query(id*2+1,mid+1,R,pos);
	}
	void main(){
		cin>>n>>m;
		bool specialAFlag = true;
		for(int i = 1;i<=n;i++){
			cin>>a[i];
			if(a[i]<a[i-1]) specialAFlag = false;
		}
		if(n<=5000){
			bf::solve();
			return ;
		}
		if(specialAFlag){
//			cout<<"here"<<endl;
			specialA::solve();
			return ;
		}
		for(int i = 1;i<=n;i++){
			pre[i] = lst[a[i]];
			lst[a[i]] = i;
		}
		for(int i = 1;i<=n;i++){
			if(pre[i]!=0)
			fix(1,1,n,pre[i]+1,i-1,pre[i]);
		}
		for(int i = 1;i<=n;i++){
			pair<int,bool> nowans = query(1,1,n,i);
//			cout<<nowans.first<<' '<<nowans.second<<endl;
			if(nowans.second){
				ans[a[i]]+=(i-nowans.first);
			}else ans[a[i]] = max(ans[a[i]],i-nowans.first);
		}
		for(int i = 1;i<=m;i++) cout<<ans[i]<<' ';
	}
}
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	solution::main();
	return 0;
}
/*
Oh no, I failed to solve Problem D
It took me more than 2.5 hours! 
Wish that I'll have a good mood in the afternoon. 
Wish that I'll get 348. 
That's my all for CSP-J.
But NOT CSP-S! 
Comment for this contest:
What is A<C<B<D?
*/
