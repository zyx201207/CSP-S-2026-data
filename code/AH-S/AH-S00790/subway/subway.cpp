#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int c,n,m,d,q;
int k[1005];
int w[1005];
int f[1005][1005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int lastid,lasttim;
		for(int j=1;j<=k[i];j++){
			int id,tim;cin>>id>>tim;
			if(j>=2){
				f[lastid][id]=f[id][lastid]=lasttim+tim;
			}
			lastid=id,lasttim=tim;
		}
	}
	for(int i=1;i<=m;i++){
		f[i][i]=0;
	}
	for(int i=1;i<=m-1;i++){
		for(int j=1;j+i<=m;j++){
			for(int k=1;k<=m;k++){
				f[i+j][j]=f[j][i+j]=min(f[i+j][k]+f[k][j],f[i+j][j]);
			}
		}
	}
	while(q--){
		int l,r;cin>>l>>r;
		cout<<f[l][r]+w[l]+w[r]<<endl;
	}
	return 0;
}

