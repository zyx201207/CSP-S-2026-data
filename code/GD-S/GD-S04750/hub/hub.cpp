#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int c,t,n,k;
int ans;
//int bfs(){
//	queue<int>q;
//	for(int i=1;i<=k;i++){
//		q.push_back()
//	}
//}
//void dfs(int x){
//	if(x==k+1){
//		int cnt=bfs();
//		ans=min(cnt,ans);
//	}
//}
int check(int x){
	int cnt=1;
	int p=x+1;
	for(int i=p+1;i<=n;i++){
		if(i-p>x){
//			cout<<p<<endl;
			cnt++;
			p=i+x;
		}
	}
	if(cnt<=k) return 1;
	else return 0; 
}
vector<int>tr[N];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			tr[u].push_back(v);
		}
			int l=1,r=n;
			while(l<=r){
				int mid=(l+r)/2; 
				if(check(mid)){
					r=mid-1;
					ans=mid;
				}else l=mid+1;
			}cout<<ans<<"\n";
	}
	return 0;
}
//13 1
//7 2
//1 2 
//2 3
//3 4
//4 5
//5 6
//6 7

