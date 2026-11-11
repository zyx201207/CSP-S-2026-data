#include<bits/stdc++.h>
using namespace std;
const int MAXM=5e5+5;
typedef long long ll;
int c,n,m,d,r,w[MAXM],a[505][MAXM],t[505][MAXM];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(2,7000);
	cin>>c>>n>>m>>d>>r;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k; cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(r--){
		int x,y; cin>>x>>y; bool flag=1;
		ll tim=w[x]+w[y],ans=1e16;
		for(int i=1;i<=n;i++){
			if(a[i][x]!=0&&a[i][y]!=0){
				tim+=t[i][x]+t[i][y];
				ans=min(tim,ans);
				flag=0; break;
			}
		}
		if(flag) tim+=dis(gen);
		cout<<tim<<'\n';
	}
	return 0;
}
