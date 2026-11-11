#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10;
int n,m,a[maxn],ans[maxn],last[maxn],go[maxn];
bool vis[maxn];
struct node{
	int l,r,id;
};
stack<node>st;
void solve1(){
	for(int i=1;i<=n;i++){
		stack<int>st;
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				st.push(a[j]);
				vis[a[j]]=1;
			}else{
				while(st.top()!=a[j]){
					vis[st.top()]=0;
					st.pop();
				}
			}
		}
		while(st.size()){
			ans[st.top()]++;
			vis[st.top()]=0;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
}
void solve(){
	cin>>n>>m;
	memset(last,-1,sizeof last);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		go[i]=last[a[i]];
		last[a[i]]=i;
	}
	if(n<=5000){
		solve1();
		return ;
	}
	for(int i=n;i>=1;i--){
		int l=go[i],r=i;
		if(st.size()&&st.top().l==i){
			ans[st.top().id]+=st.top().r-st.top().l+1;
			st.pop();
		}
		if(l==-1){
			ans[a[i]]+=i;
			continue;
		}
		while(st.size()&&l<st.top().l){
			int ansr=st.top().r,aid=st.top().id;
			int nr=st.top().l-1;
			r=nr;
			st.pop();
			ans[aid]+=ansr-st.top().l;
		}
		st.push({l,r,a[i]});
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1;
	while(T--)solve();	
	return 0;
}
