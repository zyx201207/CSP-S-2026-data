#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int M=5e5+10,N=510;
int w[M],a[N][M],t[N][M],k[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
			cin>>a[i][j]>>t[i][j];
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		int ans=w[l]+w[r],f=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==l){
					ans+=t[i][j];
					l=a[i][j];
				}
				if(l==r){
					f=1;
					break;
				}
			}
			if(f==1) break;
		}
		cout<<ans<<endl;
	}
	return 0;
}

