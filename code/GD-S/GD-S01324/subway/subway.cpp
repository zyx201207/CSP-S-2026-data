#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k[510],l[500010];
long long mus[500010],f[510][510];
vector<int> a[510],t[510],sw[500010],swv[500010];
long long buc[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>mus[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].push_back(0);
		t[i].push_back(0);
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
			l[x]++;
			sw[x].push_back(i);
			swv[x].push_back(y);
		}
	}
	for(int i=1;i<=n;i++){
		for(int x=1;x<=k[i];x++){
			buc[a[i][x]]=t[i][x];
		}
		for(int j=i+1;j<=n;j++){
			f[i][j]=1e17;
			for(int x=1;x<=k[j];x++){
				if(buc[a[j][x]]!=0){
					f[i][j]=min(f[i][j],buc[a[j][x]]+t[j][x]);
				}
			}
			f[j][i]=f[i][j];
		}
		for(int x=1;x<=k[i];x++){
			buc[a[i][x]]=0;
		}
		f[i][i]=0;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]); 
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		long long ans=1e18;
		cin>>x>>y;
		for(int xx=0;xx<l[x];xx++){
			for(int yy=0;yy<l[y];yy++){
				ans=min(ans,swv[x][xx]+swv[y][yy]+f[sw[x][xx]][sw[y][yy]]);
			}
		}
		cout<<mus[x]+mus[y]+ans<<'\n';
	}
	cout<<flush;
	return 0;
}
