#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+5;
int n,m,maxpos,ans;
ll a[N];
vector<ll>g[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		ll x=a[i];
		int pos=0;
		while(x){
			pos++;
			if(x&1)
				g[pos].push_back(a[i]);
			x>>=1;
		}
		maxpos=max(maxpos,pos);
	}
	for(int i=maxpos;i>=1;i--){
		if(g[i].size()<m)continue;
		sort(g[i].begin(),g[i].end(),cmp);
		ans=g[i][0];
		for(int j=1;j<m;j++)
			ans&=g[i][j];
		printf("%d",ans);
		return 0;
	}
	printf("0");
	return 0;
}
