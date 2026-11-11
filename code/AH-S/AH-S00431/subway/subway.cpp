#include<bits/stdc++.h>
using namespace std;
long long c,n,m,w[500009],f[500009],k[509],d,q,ans,t[509][500009];
vector<long long>a[509];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	if(n==2){
		long long x,y,sum=1000000000000000;
		cin>>k[1];
		for(int j=1;j<=k[1];j++) cin>>x>>y,t[1][x]=y,f[x]++;
		cin>>k[2];
		for(int j=1;j<=k[2];j++){
			cin>>x>>y,t[2][x]=y;
			if(f[x]!=0) f[x]++;
		}
		for(int i=1;i<=m;i++)
			if(f[i]==2) sum=min(sum,t[1][i]+t[2][i]);
		for(int i=1;i<=q;i++){
			cin>>x>>y;
			if(f[x]==2){
				if(f[y]==0) ans=t[2][x]+t[2][y];
				if(f[y]==1) ans=t[1][x]+t[1][y];
				if(f[y]==2) ans=min(t[2][x]+t[2][y],t[1][x]+t[1][y]);
			}
			else if(f[y]==2){
				if(f[x]==0) ans=t[2][x]+t[2][y];
				if(f[x]==1) ans=t[1][x]+t[1][y];
				if(f[x]==2) ans=min(t[2][x]+t[2][y],t[1][x]+t[1][y]);
			}
			else{
				if(f[x]==f[y]){
					if(f[x]==0) ans=t[2][x]+t[2][y];
					if(f[x]==1) ans=t[1][x]+t[1][y];
				}
				else{
					if(f[x]==0)	ans=t[2][x]+t[1][y]+sum;
					if(f[y]==0)	ans=t[1][x]+t[2][y]+sum;
				}
			}
			cout<<ans+w[x]+w[y]<<endl;
		}
		return 0;
	}
	return 0;
}
