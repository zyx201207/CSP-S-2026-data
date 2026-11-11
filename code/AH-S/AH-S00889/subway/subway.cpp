#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
int k[505];
int a[505][500005];
int t[505][500005];
int x[100005],y[100005];
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
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		long long ans=0;
		bool b=true;
		for(int kk=1;kk<=n;kk++){
			if(!b){
				break;
			}
			for(int j=1;j<=k[i];j++){
				if(!b){
					break;
				}
				for(int ll=x[i];ll<=y[i];ll++){
					if(a[kk][j]==ll){
						ans+=t[kk][j];
						if(ll==y[i]){
							b=false;
							break;
						}
					}
				}
			}
		}
		cout<<ans+w[x[i]]+w[y[i]]<<'\n';
	}
	return 0;
}
