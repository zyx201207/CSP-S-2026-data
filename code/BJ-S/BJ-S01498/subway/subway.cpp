#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define CS 50
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f*=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x*=10;
		x+=c-'0';
		c=getchar();
	}
	return x*f;
}
int c,n,m,s,q,w[CS],k[CS],a[CS][CS],t[CS][CS],ans=0,x,y;
signed main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>s>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		cin>>x>>y;
		ans=0;
		ans+=w[x];
		ans+=w[y];
		int jans=ans;
			for(int j=1;j<=k[1];j++){
				if(n==2){
					for(int l=1;l<=k[2];l++){
						if(n==3){
							for(int z=1;z<=k[3];z++){
								for(int i=1;i<=n;i++){
									if(a[i][j]==a[i][z]){
										jans+=t[i][j];
										jans+=t[i][z];
									}
									if(a[i][l]==a[i][z]){
										jans+=t[i][l];
										jans+=t[i][z];
									}
									if(a[i][j]==a[i][l]){
										jans+=t[i][l];
										jans+=t[i][j];
									}
								}
								ans=min(ans,jans);
							}
						}else{
							for(int i=1;i<=n;i++){
								if(a[i][l]==a[i][j]){
									jans+=t[i][j];
									jans+=t[i][l];
								}
							}
						}
					}
					ans=min(ans,jans);
				}else{
					cout<<ans;
					break;
				}
			}
	}
	return 0;
}
