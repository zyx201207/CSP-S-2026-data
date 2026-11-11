#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(x,y,z) for(int x=y;x<=z;++x)
#define per(x,y,z) for(int x=y;x>=z;--x)
#define endl '\n'
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;
const int N=500005;
int n,m,a[N],ans[N],fi[N];
bool vis[N];
//map<int,int> mp;
//stack<int> s;
vi sd;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.ans","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	rep(i,1,n)cin>>a[i];
	//per(i,n,1)cin>>a[i];
//	bf
//		rep(i,1,n){
//			rep(j,1,n-i+1)vis[j]=0;
//			rep(j,1,n-i+1){
//				if(!vis[a[j]])vis[a[j]]=j,++ans[a[j]];
//				else rep(k,vis[a[j]]+1,j-1){
//					if(vis[a[k]]==k)vis[a[k]]=0;
//					--ans[a[k]];
//				}
//			}
//		}
//		rep(i,1,m)cout<<ans[i]<<' ';
//		cout<<endl;
	rep(i,1,n){
		sd.clear();
		rep(j,0,n)vis[a[j]]=0;
		rep(j,i,n){
		if(vis[a[j]]){
			while(/*s.top()*/sd.back()!=a[j]){
				vis[sd.back()]=0;
				//mp[s.top()]=0;
				sd.pop_back();//,s.pop();
			}
		}else{
			vis[a[j]]=1;//,s.push(a[i]);
			sd.push_back(a[j]);
			//mp[a[i]]=1;
		}}
		//for(auto&x:mp)++ans[x.fi];
		for(auto&x:sd)++ans[x];
	}
	rep(i,1,m)cout<<ans[i]<<' ';
	cout<<endl;
	return 0;
}