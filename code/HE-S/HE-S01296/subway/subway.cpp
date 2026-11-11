#include<bits/stdc++.h>
using namespace std;
long long w[500005];
long long s[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int a;
		long long t;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			s[a]=t;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		long long ans=(w[x]+w[y]+s[x]+s[y]);
		cout<<ans<<endl;
	}
	return 0;
}
