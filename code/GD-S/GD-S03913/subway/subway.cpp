#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[500005],t[500005][500005],a[500005][500005];
int z;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>k[cnt++];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
		z=t[i][1];
	}
	int ans=0;
	for(int i=1;i<=q;i++){
		int qd,zd;
		cin>>qd>>zd;
		ans+=w[qd];
		ans+=w[zd];
		ans+=(2*z);
		while(qd<=zd){
			ans+=(2*w[qd++]);
			ans+=(2*z);
		}
		cout<<ans;
	}
	
	return 0;
} 
