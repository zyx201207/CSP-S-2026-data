#include <bits/stdc++.h>
using namespace std;
long long n,k,sum=INT_MAX;
vector<long long> vv[1000000+10];
long long fa[1000000+10];
long long a[2010][2010];
long long c,t;
vector<long long> v;
long long Find(long long x){
	if(x==fa[x])return x;
	return fa[x]=Find(fa[x]);
}
bool cr(long long x,long long y){
	long long xx=Find(x),yy=Find(y);
	if(xx==yy)return false;
	fa[xx]=yy;
	return true;
}
long long ans[3010];
void dfs(long long pos){
	if(pos>n){
		if(v.size()==k){
			long long p=v.size();
			for(int i=1;i<=n;i++)fa[i]=i;
			for(auto i:v){
				for(auto j:vv[i]){
					for(auto k:v){
						if(k==j){
							if(cr(i,j))p--;
							break;
						}
					}
					
				}
			}
			if(p>2)return;
//			for(auto i:v){
//			cout << i << ' ';
//		}
//		cout << endl;
			long long ma=0;
			for(int i=1;i<=n;i++){
//				for(auto j:v){
//					if(j==i)goto E;
//				}
				long long mi=INT_MAX;
				for(auto j:v){
					mi=min(mi,a[i][j]);
				}
				ma=max(ma,mi);
			}
			sum=min(ma,sum);
		}
		return;
	}
	if(n-pos+1<k-v.size())return;
	dfs(pos+1);
	if(v.size()<k){
		v.push_back(pos);
		dfs(pos+1);
		v.pop_back();
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--){
		memset(a,0x3f,sizeof(a));
		sum=INT_MAX;
		cin >> n >> k;
		for(int i=1;i<=n;i++){
			vv[i].clear();
		}
		for(int i=1;i<=n;i++){
			a[i][i]=0;
			if(i!=n){
				long long x,y;
				cin >> x >> y;
				vv[x].push_back(y);
				vv[y].push_back(x);
				a[x][y]=a[y][x]=min(min(a[x][y],a[y][x]),1ll);
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(a[i][k]!=a[1999][1999] && a[k][j]!=a[1999][1999])a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
				}
			}
		}
		dfs(1);
		cout << sum << '\n';
	}
	return 0;
}
