#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,n,m,d,q,w[N],k[N],a[N],t[N],x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)cin>>a[j]>>t[j];
	}
	for(int i=1;i<=q;i++){
		int s=0;
		cin>>x>>y;
		for(int j=x;j<=y;j++)s+=w[j]+a[j]+t[j];
		cout<<s<<"\n";
	}
	return 0;
}
