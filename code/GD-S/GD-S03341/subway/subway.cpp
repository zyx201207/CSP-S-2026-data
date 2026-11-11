#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subuway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	int tm[500005];
	int xn[505][500005];
	int xt[505][500005];
	int xn1[500005];
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>tm[i];
	int t;
	for(int i=1;i<=n;i++) {
		cin>>t;
		for(int j=1;j<=t;j++){
			cin>>xn[i][j];
			cin>>xt[i][xn[i][j]];
			xn1[xn[i][j]]=j;
		}
	}
	int q1,q2;
	int ans=0;
	int minn=9999;
	int mint;
	int minxn;
	for(int i=1;i<=q;i++){
		cin>>q1>>q2;		
		ans+=tm[q1];
		while(q1!=q2){
			
				for(int j=1;j<=n;j++){
					if(xt[j][q1]!=0){
						mint=min(mint,xt[j][q1]);
						minxn=j;
					}
				}
				ans+=mint;
				q1=xn[minxn][xn1[q1]+1];
		}
	}
		ans+=tm[q2];
		cout<<ans;
	return 0;
}
