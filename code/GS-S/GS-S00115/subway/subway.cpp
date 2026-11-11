#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int w[N],k[N],a[N],t[N],ans[N];
int x[3],y[3];
int c,n,m,d,q;
int r=1;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
		}
	}
	for(int i=1;i<=n;i++){
		cin>>x[r]>>y[r];
		r++;
	}
	for(int i=1;i<=q;i++){
		for(int j=1;j<=a[i];j++){
			ans[i]+=w[j];
			ans[i]+=t[j];
		}
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
