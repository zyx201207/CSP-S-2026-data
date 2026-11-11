#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,w[100005],c,d,q,t[10005][10005],a[10005][10005],r1[100001],r2[100001],sum,k[10005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		sum+=w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			sum+=t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>r1[i]>>r2[i];
	}
	cout<<sum<<'\n';
}
