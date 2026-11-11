#include <bits/stdc++.h>
using namespace std;

const int MAXN(1E4+5);
bool a[MAXN][MAXN];
long long t[MAXN][MAXN];
long long w[MAXN];
long long ans;
long long k[MAXN];
long long c,n,m,d,q;

void f(int x,int y,long long sum){
	if(x==y){
		ans=min(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(a[x][i]==true){
			a[x][i]=false;
			sum+=t[x][i];
			for(int j=1;j<=n;j++){
				sum+=t[j][i];
				a[k[j]][i]=false;
				f(j,y,sum);
				sum-=t[j][i];
				a[k[j]][i]=true;
			}
			a[x][i]=true;
			sum-=t[x][i];
		}
	}
	return;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		if(k[i]==1) continue;
		for(int j=1;j<=k[i];j++){
			int a1,t1;
			cin>>a1>>t1;
			a[a1][i]=true;
			t[a1][i]=t1;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=0x3f3f3f3f;
		f(x,y,w[x]+w[y]);
		cout<<ans<<endl;
	}
	return 0;
}