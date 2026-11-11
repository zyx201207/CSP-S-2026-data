#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500005],u[505];
struct node{
	long long a,t;
}s[505];
vector<node> r;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		long long k;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			long long a,t;
			scanf("%lld%lld",&a,&t);
			u[a]=t;
		}
	}
	while(q--){
		long long x,y;
		scanf("%lld%lld",&x,&y);
		long long sum=w[x]+w[y];
		for(int i=x;i<=y;i++){
			sum+=u[i];
		}
		cout<<sum<<endl;
	}
	return 0;
}
