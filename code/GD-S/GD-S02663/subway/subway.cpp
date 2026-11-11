#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	unsigned long long c,n,m,d,q,maxki=0;
	cin>>c>>n>>m>>d>>q;
	unsigned long long ans[q+5]={0},w[m+5],ki[n+5],fx[q+5],fy[q+5],x[q+5],y[q+5];
	unsigned long long a[n+5][1100],t[n+5][1100];
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>ki[i];
		maxki=max(maxki,ki[i]);
		for(int j=1;j<=ki[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=ki[i];j++){
			if(a[i][j]==x[i]){
				fx[i]=j;
			}
			if(a[i][j]==y[i]){
				fy[i]=j;
			}
		}
	}
	for(int i=1;i<=q;i++){
		ans[i]+=w[fx[i]]+w[fy[i]]+a[i][fx[i]];
		cout<<ans[i]<<endl;
	}
	return 0;
} 
