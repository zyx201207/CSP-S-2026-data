#include<bits/stdc++.h>
using namespace std;
unsigned long long c,n,m,d,q,w[500005],k,a[510][510],x,y,z,e;
struct station{
	unsigned long long l,li[25],s[25];
}b[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=9223372036854775800;
		}
		a[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			b[x].li[++b[x].l]=i;
			b[x].s[b[x].l]=y;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=b[i].l;j++){
			for(int k=j+1;k<=b[i].l;k++){
				a[b[i].li[j]][b[i].li[k]]=min(a[b[i].li[j]][b[i].li[k]] , b[i].s[j]+b[i].s[k]);
				a[b[i].li[k]][b[i].li[j]]=a[b[i].li[j]][b[i].li[k]];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j]>a[i][k]+a[j][k]){
					a[i][j]=a[i][k]+a[j][k];
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		z=9223372036854775800;
		for(int j=1;j<=b[x].l;j++){
			for(int k=1;k<=b[y].l;k++){
				z=min(z,a[b[x].li[j]][b[y].li[k]]+b[x].s[j]+b[y].s[k]);
			}
		}
		z+=w[x]+w[y];
		cout<<z<<endl;
	}
	return 0;
}
