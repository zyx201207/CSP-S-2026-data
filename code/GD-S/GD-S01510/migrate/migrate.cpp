#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int n , ce,t,a[N],d,ans = 0,vis[N],d[N];
vector<int> G[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>ce>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<n;i++) d[i] = a[i+1]-a[i];
		sort(d+1,d+1+n);
		if(d[1] == d[n]){
			cout<<n-3<<endl;
		}
		else{
			cout<<n-2<<endl;
		}
	}
	return 0;
}
