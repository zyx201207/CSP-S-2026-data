#include <bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int N=5*1e5+10;
constexpr ll INF=1e18;
struct node{
	int sum,id;
}a[N];
int n,m;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].id;
		a[i].sum=i;
	}
	map<int,int> mp;//first:数值 second:下标 
	for(int i=1;i<=n;i++){
		mp.clear();
		for(int j=i;j<=n;j++){//当前的位置 
			if(mp.find(a[j].id)!=mp.end()){//x现在的序号前面出现过 
				int from=mp[a[j].id];
				mp.erase(a[j].id);
				for(int k=from;k<j;k++){
					//if(mp.find(a[k].id)!=mp.end()){//还没哦被删 
					a[k].sum--;
					mp.erase(a[k].id);
					//} 
				}
			}else{
				mp[a[j].id]=j;
			}
		}
	}
	vector<ll> ans(m+1);
	for(int i=1;i<=n;i++){
		ans[a[i].id]+=a[i].sum;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	solve();
	return 0;
}
/*
4 3
1 2 1 3
10 3
3 1 2 1 3 2 3 1 2 1
*/
