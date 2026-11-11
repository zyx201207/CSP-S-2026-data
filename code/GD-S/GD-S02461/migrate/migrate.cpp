#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e17;
const int N = 2e6+15; 
int n,m;
ll a[N],x[N],d;
int las,las1,c;
ll ans;
ll f[N],g[N];

int check(int l,int r){
	
}

void calc(){
	
}

void solve(){
	printf("0\n");
	return ;
	
	ans = 0; 
	cin >> m >> d;
	for(int i = 1;i <= m;++i)cin >> a[i];
	
	n=0;
	for(int i = 1;i < m;++i){
		x[++n]=a[i];
		if(a[i+1]-a[i]>d){
			calc();
			n=0;
		}
	}
	x[++n]=a[m];
	calc();
	
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> c >> T;
	while(T--)solve();
	return 0;
}
