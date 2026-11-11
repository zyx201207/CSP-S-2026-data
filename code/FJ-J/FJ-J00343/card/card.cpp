#include<bits/stdc++.h>

using namespace std;
int n,m;
int a[500005],ans[300005];
stack<int>pk;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m ; 
	for(int i=1;i<=n;i++)cin >> a[i] ;
	for(int i=1;i<=n;i++){
		vector<int>tong(m+1,0);
		for(int j=i;j<=n;j++){
			if(tong[a[j]]){
				while(pk.top()!=a[j]){
					tong[pk.top()]-- ;
					pk.pop() ;
				}
				continue;
			}
			tong[a[j]]++;
			pk.push(a[j]) ;
		}
		while(!pk.empty()){
			ans[pk.top()]++;
			pk.pop() ;
		}
	}
	for(int i=1;i<=m;i++){
		cout << ans[i] ;
		if(i!=m) cout << " " ;
	}
	cout << '\n' ;
	return 0 ;
}
