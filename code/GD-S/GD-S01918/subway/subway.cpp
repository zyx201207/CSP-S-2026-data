#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[5][300005],t[5][300005],w[300005];
signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		a[1][i]=0x3f3f3f;
		a[2][i]=0x3f3f3f;
		t[1][i]=0x3f3f3f;
		t[2][i]=0x3f3f3f;
	}
	int k;
	cin>>k;
	for(int i=1;i<=k/2;i++){
		cin>>a[1][i]>>t[1][i];
	}
	cin>>k;
	for(int i=1;i<=k/2;i++){
		cin>>a[2][i]>>t[2][i];
	}
	int minn=0x3f3f3f;
	for(int i=1;i<=n;i++){
		minn=min(minn,t[1][i]+t[2][i]);
	}
	for(int i=1;i<=k/2;i++){
		cin>>a[2][i]>>t[2][i];
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		if(x==y){
			cout<<0;
			continue;
		}
		bool X=0,Y=0;
		for(int i=1;i<=k/2;i++){
			if(a[1][i]==x) X=1;
			else if(a[1][i]==y) Y=1;
		}
		if(X&&Y){
			cout<<w[x]+w[y]+min(t[1][x],t[2][x])+min(t[1][y],t[2][y])<<endl;
			continue;
		}
		X=0;
		Y=0;
		for(int i=1;i<=k/2;i++){
			if(a[2][i]==x) X=1;
			else if(a[2][i]==y) Y=1;
		}
		if(X&&Y){
			cout<<w[x]+w[y]+min(t[1][x],t[2][x])+min(t[1][y],t[2][y])<<endl;
			continue;
		}
		cout<<w[x]+w[y]+minn+min(t[1][x],t[2][x])+min(t[1][y],t[2][y])<<endl;
	}
	return 0;
} 
