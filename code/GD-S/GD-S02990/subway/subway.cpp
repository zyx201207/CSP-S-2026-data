#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,d,q,k;
int w[N];
struct node{
	int a,t;
}e[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		cin >> k;
		for(int j=1;j<=k;j++){
			cin >> e[j].a >> e[j].t;
		}
	}
	int x,y;
	while(q--){
		cin >> x >> y;
		int ans=w[x]+w[y];
		cout << ans << '\n';
	}
	return 0;
} 
