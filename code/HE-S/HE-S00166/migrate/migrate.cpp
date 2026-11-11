#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll c,T,a[2000005],cnt;
ll  n,d,ans[2000005];
void dfs(ll k){
	for(ll i=k+1;a[i]-a[k]<=d && i<=n;i++){
		ans[i]++;
		dfs(i);
	}
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--) {
		cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			a[i]+=1e18+5;
		}
		for(int i=1;i<=n;i++){
			dfs(i);
		}
		for(int i=1;i<=n;i++){
			if(ans[i]==2){
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
