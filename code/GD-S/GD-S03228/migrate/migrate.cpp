#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e6 + 6;
int c,t,n,d,x[N],mp[5003][5003];

int emt_bless_me(int rp){return rp++;}

void emt(int now,int step){
	if(now == n)return;
	for(int i = now + 1;i <= n;i++){
		if(x[i] - x[now] <= d){
			mp[i][step + 1]++;
			//cout<<i<<' '<<step + 1<<' '<<mp[i][step + 1]<<'\n';
			emt(i,step + 1);
		}
	}
	return;
}

int main(){
	cin.tie(nullptr) -> ios_base::sync_with_stdio(false);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans = 0;
		memset(x,0,sizeof(x));
		memset(mp,0,sizeof(mp));
		cin>>n>>d;
		for(int i = 1;i <= n;i++)cin>>x[i];
		for(int i = 1;i <= n;i++){
			memset(mp,0,sizeof(mp));
			emt(i,0);
			for(int j = 1;j <= n;j++)for(int k = 1;k <= 5000;k++){
				if(mp[j][k] && mp[j][k] != 2)break;
				if(mp[j][k] == 2)ans++;
			}
			//cout<<'\n';
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

1
2

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0
1
*/
