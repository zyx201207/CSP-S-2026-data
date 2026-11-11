#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long c,n,m,d,q,w[N],k[N],a[N],t[N],ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}sort(w+1,w+1+m);
	ans+=w[1]+w[2];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
		}
		sort(t+1,t+1+k[i]);
		ans+=t[1]+t[2];
	}
	cout<<ans;
	return 0;
} 
