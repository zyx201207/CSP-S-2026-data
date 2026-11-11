#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,a[501][50001],t[501][50001],w[50001];
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}for(int i=1;i<=q;i++){
		ll s,e;
		cin>>s>>e;
		ll ans=w[s]+w[e],xl,xpp;
		for(int l=1;l<=n;l++){
			for(int r=1;a[l][r]!=0;r++){
				if(a[l][r]=s)xl=s;
			}
		}for(int l=1;a[xl][l]!=0;l++){
			for(int k=1;k<=n;k++){
				if(k==xl)continue;
				for(int r=1;r<=n;r++){
					if(a[k][r]==a[xl][l]){
						ans+=t[k][r]+t[xl][l];
						break;
					}
				}
			}
		}cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

