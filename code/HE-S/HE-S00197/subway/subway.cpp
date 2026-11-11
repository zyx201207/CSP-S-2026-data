#include<bits/stdc++.h>
using namespace std;
long long ans;
int c,n,m,d,q,w[500005],a[505][50005],k[505],t[505][50005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
	}
	while(q--){
		ans=0;
		int s,e;
		cin>>s>>e;
		bool flag1=false,flag2=false;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(!flag1&&a[i][j]==s) ans+=w[j]+t[i][j];
				if(!flag2&&a[i][j]==e) ans+=w[j]+t[i][j];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
