#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int c,n,m,d,q;
ll w[1005];
ll f[1005][1005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			f[i][j]=INT_MAX;
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		vector<int> a(k+1);
		vector<int> t(k+1);
		cin>>a[1]>>t[1];
		for(int j=2;j<=k;j++){
			cin>>a[j]>>t[j];
			for(int p=1;p<j;p++){
				f[a[p]][a[j]]=t[j]+t[p];
				f[a[j]][a[p]]=t[j]+t[p];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int l,r;
		cin>>l>>r;
		cout<<f[l][r]<<"\n";
	}
	return 0;
}
