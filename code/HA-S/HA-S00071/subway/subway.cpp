#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	vector<int>w(m+1),k(n+1);
	vector<int[1009]>a(n+1),t(n+1);
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)cin>>a[i][j]>>t[i][j];
	}
	int mn=2147483647;
	for(int i=1;i<=n;i++)mn=min(mn,t[1][i]+t[2][i]);
	while(q--){
		int x,y;
		cin>>x>>y;
		bool x1=0,y1=0;
		for(int i=1;i<=n;i++){
			if(a[i][1]==x||a[i][2]==x)x1=1;
			if(a[i][1]==y||a[i][2]==y)y1=1;
		}
		if(x1==y1)cout<<0<<'\n';
		else cout<<mn<<'\n';
	}
	return 0;
}
