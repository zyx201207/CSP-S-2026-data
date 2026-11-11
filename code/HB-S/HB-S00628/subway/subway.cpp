#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,ans;
long long w[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		ans-=w[i];
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			int y,z;
			cin>>y>>z;
			ans+=z;
		}
	}
	cout<<ans;
	return 0;
}

