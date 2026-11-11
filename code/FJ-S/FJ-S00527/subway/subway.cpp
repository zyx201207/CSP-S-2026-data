#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,ans,w[700000],k[785000],a[5000][5000],l[5000][5000],x[500000],y[500000];
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
			cin>>a[i][j]>>l[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	sort(w,w+n+1);
	for(int jh=1;jh<=q;jh++){
		long long mmin2=INT_MAX;
	for(int i=1;i<=n;i++){
		mmin2=min(mmin2,l[0][0]);
	}
	cout<<w[0]+mmin2*(x[jh]-y[jh])+w[1]<<endl;
	}
	return 0;
}
