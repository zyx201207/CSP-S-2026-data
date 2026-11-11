#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int sum,m;
int n,num[100],ans=0;
void bfs(int l,int r,int t){
	queue<pair<int,int>> q;
	q.push({l,0});
	while(!q.empty()){
		int u = q.front().first,st = q.front().second;
		q.pop();
		if(u == r and st == t){
			sum ++;
		}else if(u >= r and st >= t){
			continue;
		}
		for(int i = u+1;i <= upper_bound(num+1,num+1+n,num[u]+m)-num-1;i ++){
			q.push({i,st+1});
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	if(c <= 2){
		while(t --){
			cin>>n>>m;
			ans = 0;
			for(int i = 1;i <= n;i ++){
				cin>>num[i];
			}for(int l = 1;l <= n;l ++){
				for(int r = l;r <= n;r ++){
					if(r-l<=2)continue;
					int cnt = 0,t = l;
					bool flag = true;
					while(t < r){
						if(num[t+1]-num[t] > m){
							flag = false;
							break;
						}
						t = upper_bound(num+1,num+1+n,num[t]+m)-num-1;
						cnt ++;
					}if(!flag)continue;
					sum=0;
					bfs(l,r,cnt);
					if(sum==2){
						ans ++;
					}
//					cout<<l<<" "<<r<<" "<<cnt<<" "<<sum<<endl;
				}
			}cout<<ans<<endl;
		}
	}
	return 0;
}

