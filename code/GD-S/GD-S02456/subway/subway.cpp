#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll c,n,m,d,q,s,e;
ll w[500005],a[505][505],t[505][505];

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i++) cin>>w[i];
	for(int i = 1;i <= n;i++){
		int k;
		cin>>k;
		for(int j = 1;j <= k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	} 
	for(int i = 1;i <= q;i++){
		cin>>s>>e;
		cout<<s * e;
	}
	
	
	return 0;
}
