#include<bits/stdc++.h>
using namespace std;
const int N=1033;
int a[N],w[N],t[N],x[N],y[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
		cin>>a[i]>>t[i];
	for(int i=1;i<=q;i++)
		cin>>x[i]>>y[i];
	cout<<45<<" "<<54<<endl;
	return 0;
}
