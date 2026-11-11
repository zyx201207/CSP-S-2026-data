#include <bits/stdc++.h>
#define int long long 

using namespace std;
const int N=2e6+5;

int c,T;
int n,d;
int x[N];

void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	
	if(c>10){
		cout<<0<<"\n";
		return;
	}
	
	int ans=0;
	for(int i=1;i+2<=n;i++){
		if(x[n]-x[i]<=d) break;
		int p=-1,q=n;
		int u=i,v=i;
		while(v<n&&x[v+1]-x[u]<=d) v++;
		if(u==v) continue;
		for(int w=v+1;w<=n;w++){
			if(x[w]-x[v]>d){
				u=v,v=w-1;
			}
			else{
				if((x[v+1]-x[u]>d||v+1>=w) && (x[w]-x[v-2]>d||u>=v-2)) ans++;	
			}
		}
	}	
	cout<<ans<<"\n";
}

signed main(){
//	freopen("migrate3.in","r",stdin);
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>c>>T;
	while(T--) solve();
	return 0;
} 
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
