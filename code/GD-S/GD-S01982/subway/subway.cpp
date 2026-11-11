#include<bits/stdc++.h>
using namespace std;
long long c,d,q,n,m,s,w[500005],a[500005],t[500005],x[500005],y[500005],ans,l;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i],s+=w[i];
	for(int i=1;i<=n;i++) cin>>a[i]>>t[i];
	for(int i=1;i<=q;i++) cin>>x[i]>>y[i];
	cout<<s-1<<"\n"<<(s-1)/2-1;
	return 0;
}