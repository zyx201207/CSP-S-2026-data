#include<bits/stdc++.h>
using namespace std;
int c,T,n;
long long d;
const int N = 2e6 + 110;
long long x[N];
int t,ans,minn;
void dfs(int now,int end,int s){
	if(now == end){
		if(s == minn){
			t++;
		}
		if(s < minn){
			minn = s;
			t = 1;
		}
		return;
	}
	for(int i=now+1;i<=end;i++){
		if(x[i]-x[now]<=d){
			dfs(i,end,s+1);
		}
		else break;
	}
}
int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin >> c >> T;
	
	while(T--){
		ans = 0;
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				t = -1;
				minn = 1e9;
				dfs(i,j,0);
				if(t == 2){
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}
