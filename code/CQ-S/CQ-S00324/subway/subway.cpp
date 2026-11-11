#include<bits/stdc++.h>
using namespace std;
int w,n,m,d,q,a[500005],c[505][500005];
long long s=0,t=0;
bool b[505][500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>w>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int r,l;
			cin>>r>>l; 
			b[i][r]=1;
			c[i][r]=l;                                 
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		if(n==1){
			cout<<a[x]+a[y]+c[1][x]+c[1][y]<<'\n';
			return 0;
		}
		if(n==2){
			long long o;
			for(int i=1;i<=n;i++){
				if(b[i][x]==1&&b[i][y]==1){
					o=a[x]+a[y]+c[i][x]+c[i][y];
					if(s==0) s=o;
					else s=min(s,o);
				}
			}
			for(int i=1;i<=m;i++){
				if(b[1][i]==1&&b[2][i]==1&&i!=x&&i!=y){
					o=c[1][i]+c[2][i];
					if(t==0) t=o;
					else t=min(t,o);
				}
			}
			if(b[1][x]==1&&b[2][y]==1){
				o=a[x]+a[y]+c[1][x]+c[2][y]+t;
				if(s==0) s=o;
				else s=min(s,o);
			}
			else if(b[1][y]==1&&b[2][x]==1){
				o=a[x]+a[y]+c[1][y]+c[2][x]+t;
				if(s==0) s=o;
				else s=min(s,o);
			}
			cout<<s<<'\n';
		}
	}
	return 0;
} 
