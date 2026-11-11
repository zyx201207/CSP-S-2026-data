#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=500005;
int c,n,m,d,q,k[505],w[500005],f[6005][6005],st[100005],ed[100005]; 
vector<int> a[505],t[505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	memset(f,0x3f,sizeof(f));
//	cout<<1;//
	cin>>c>>n>>m>>d>>q;
//	cout<<2;//
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
//	cout<<3;//
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].resize(k[i]+1);
		t[i].resize(m+1,0x3f3f3f3f3f3f3f3f);
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][a[i][j]];
		}
	}
//	for(int i=1;i<=n;i++){//
//		for(int j=1;j<=m;j++){//
//			if(t[i][j]<=1000000000){//
//				cout<<i<<" "<<j<<" "<<t[i][j]<<"\n";//
//			}//
//		}//
//	}//
//	cout<<4;//
	for(int i=1;i<=q;i++){
		cin>>st[i]>>ed[i];
	}
//	cout<<5;//
	if(c<=11){
//		cout<<1;//
		for(int i=1;i<=n;i++){
//			cout<<2;//
			for(int j=1;j<=k[i];j++){
				for(int jj=j+1;jj<=k[i];jj++){
					f[a[i][j]][a[i][jj]]=f[a[i][jj]][a[i][j]]=min(f[a[i][j]][a[i][jj]],t[i][a[i][j]]+t[i][a[i][jj]]);
				}
			}
		}
//		cout<<3;//
		for(int i=1;i<=m;i++){
//			cout<<4;//
			for(int j=i+1;j<=m;j++){
				for(int k=1;k<=m;k++){
					f[i][j]=f[j][i]=min(f[i][j],f[i][k]+f[j][k]);
				}
			}
		}
//		cout<<5;//
		for(int i=1;i<=q;i++){
			cout<<f[st[i]][ed[i]]+w[st[i]]+w[ed[i]]<<"\n";
		}
//		for(int i=1;i<=m;i++){//
//			for(int j=i+1;j<=m;j++){//
//				if(f[i][j]<=1000000000){//
//					cout<<i<<" "<<j<<" "<<f[i][j]<<"\n";//
//				}//
//			}//
//		}//
		return 0;
	}
	if(c>=12&&c<=19){
		
	}
	return 0;
} 
