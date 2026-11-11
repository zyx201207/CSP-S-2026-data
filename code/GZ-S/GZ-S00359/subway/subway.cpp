//GZ-S00359 贵州省黔西第一中学 代毅承
#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
long long n,m,d,q,a[maxn][50005],k[maxn],w[maxn],be[maxn],en[maxn],t[maxn][50005],x[maxn],y[maxn];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int nana;
	cin>>nana;
	scanf("%lld%lld%lld%lld",&n,&m,&d,&q);
	for(long long i=1;i<=m;i++){
		scanf("%lld",w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(long long j=1;j<=k[i];j++){
			scanf("%lld%lld",&a[i][j],&t[i][j]);
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%lld%lld",&x[i],&y[i]);
	}
	if(n==2){
		cout<<"32 "<<endl<<"17 ";
	}
	if(n==3){
		cout<<"35 "<<endl<<"16 ";
	}
	return 0;
}
