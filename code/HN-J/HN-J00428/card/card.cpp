#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e5+25;
int n,m;
int a[N];
int x[N];
deque<int>q;
unordered_map<int,int>mp;
void solve(){
	cin>>n>>m;
	if(m==1){
		cout<<n/2+n%2;
		return ;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(mp[a[j]]>=1){
				while(q.size()){
					int f=q.back();
					mp[f]--;
					q.pop_back();
					if(f==a[j])break;
				}
				mp[a[j]]=0;
			}
			mp[a[j]]++;
			q.push_back(a[j]);
		}
		while(q.size()){
			int f=q.back();
			q.pop_back();
			x[f]++;
		}
		mp.clear();
		while(q.size()){
			q.pop_back();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<x[i]<<' ';
	}
	return ;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
/*
4 3
 1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
