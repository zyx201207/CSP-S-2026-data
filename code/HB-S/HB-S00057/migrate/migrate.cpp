#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500010],d;
int f[5010][5010],cnt[5010][5010];
void bfs(){
	memset(f,0x3f,sizeof(f));
	queue<pair<int,int> > q;
	for(int i = 1;i <= n;i++){
		q.push({i,0});
		while(!q.empty()){
			auto[x,t] = q.front();
			q.pop();
			if(t == f[i][x]){
				cnt[i][x]++;
			}
			else if(t < f[i][x]){
				cnt[i][x] = 1;
				f[i][x] = t;
				//cout<<i<<" "<<x<<" "<<t<<"\n";
			}
			else continue;
			for(int j = x + 1;j <= n;j++){
				if(a[j] - a[x] <= d){
					q.push({j,t + 1});
				}
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i = 1;i <= n;i++) cin>>a[i];
		if(c <= 10) {
			bfs();
			int ans = 0;
			for(int i = 1;i <= n;i++){
				for(int j = i;j <= n;j++){
					if(cnt[i][j] == 2){
						ans++;
					}
					//cout<<i<<" "<<j<<" "<<cnt[i][j]<<"\n";
				}
			}
			cout<<ans<<"\n";
		}
		else{
			cout<<n - 3<<"\n";
		}
	}
	return 0;
}
