#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,n,a[1005][10005],m,k,q,d,w[500005],t[505][20005],cc[505][20004];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i=1;i<=1004;++i){
		for(int j=1;j<=10001;++j){
			a[i][j]=0x3fffffff;
		}
	}
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		cin>>k;
		for(int j=1;j<=k;++j){
			cin>>cc[i][j]>>t[i][cc[i][j]];
		
		}
		for(int j=1;j<k;++j){
			a[cc[i][j]][cc[i][j+1]]=0;
		}
	}
	for(int kk=1;kk<=n;++kk){
		for(int i=1;i<=m;++i){
			for(int j=1;j<=m;++j){
				if(a[i][j]>t[i][kk]+t[kk][j]){
					a[i][j]=t[i][kk]+t[kk][j];
				}
			}
		}
	}
	while(q--){
		ll xx,yy;
		cin>>xx>>yy;
		cout<<a[xx][yy]+w[xx]+w[yy]<<"\n";
	}
	return 0;
}

