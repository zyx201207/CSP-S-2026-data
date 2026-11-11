#include<bits/stdc++.h>
using namespace std;
int x[2000005],dis[2000005],n,d;
bool check(int x,int y){
	int l = x+1,r = y-1;
	int cnt = 0;
	for(int i = l+1;i <= r;i++){
		if(dis[i] > d){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin >> c >> t;
	long long ans = 0;
	while(t--){
		cin >> n >> d;
		memset(x,0,sizeof(x));
		for(int i = 1;i <= n;i++){
			cin >> x[i];
			dis[i] = x[i]-x[i-1];
		}
		for(int i = 1;i <= n-2;i++){
			for(int j = i+2;j <= n;j++){
				if(check(i,j)){
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
