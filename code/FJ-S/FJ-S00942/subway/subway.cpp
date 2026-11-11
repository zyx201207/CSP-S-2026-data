#include<bits/stdc++.h>
using namespace std;
long long w[100005],c,b;
long long a[500][100005];
long long t[500][100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		int y;
		cin>>y;
		for(long long j=1;j<=y;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(long long i=1;i<=q;i++){
		cin>>c>>b;
		long long ans=w[c]+w[b];
		for(long long j=c;j<b;j++){
			ans+=t[j][j+1];
			ans+=t[j][j];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
