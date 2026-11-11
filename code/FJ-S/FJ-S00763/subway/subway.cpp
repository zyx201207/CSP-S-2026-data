#include<bits/stdc++.h>
using namespace std;

long long c,n,m,d,q;
const int N=2000+5;
long long w[N];
long long a[505][N],t[505][N];
long long g[2005][2005];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i][0]);
		for(int j=1;j<=a[i][0];j++){
			scanf("%lld",&a[i][j]);
		}
		for(int j=1;j<=a[i][0];j++){
			scanf("%lld",&t[i][j]);
		}
	}
	
	long long x,y;
	long long ans=0;
	while(q--){
		scanf("%lld%lld",&x,&y);
		ans=w[x]+w[y];
		int flag1=0,flag2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i][0];j++){
				if(a[i][j]==x && !flag1) flag1++;
				if(a[i][j]==y && flag1 && !flag2) flag2++;
			}
			if(flag1 && flag2) continue;
		}
		if(flag1 && flag2){
			cout<<ans<<endl;
			continue;
		}
	}
	return 0;
}

