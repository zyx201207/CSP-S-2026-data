#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[501][500001],T,m,d,q,k[501],w[500001],t[501][500001],x,y,b,s,c;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>T>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){cin>>k[i];for(int j=1;j<=k[i];j++)cin>>a[i][j]>>t[i][j];}
	for(int i=1;i<=q;i++){
		cin>>x>>y;s=INT_MAX;
		for(int j=1;j<=n;j++){
			b=0,c=0;
			for(int l=1;l<=k[j];l++)if(a[j][l]==x||a[j][l]==y)b++,c+=t[j][l];
			if(b==2)s=min(s,c);
		}cout<<s+w[x]+w[y]<<'\n';
	}
	return 0;
}
