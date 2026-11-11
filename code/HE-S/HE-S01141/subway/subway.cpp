#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y;
long long w[500005];
long long k[500005];
long long a[505][500005];
long long t[505][500005];
long long h;
int main(){
	freopen("subway.in","w",stdin);
	freopen("subway.out","r",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	if(c==0){
		for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				scanf("%lld%lld",&a[i][j],&t[i][j]);
			}
		}
		for(int r=1;r<=q;r++){
			scanf("%d%d",&x,&y);
			for(int i=1;i<=n;i++){
				int f1,f2;
				f1=find(a[i]+1,a[i]+k[i]+1,x)-a[i];
				f2=find(a[i]+1,a[i]+k[i]+1,y)-a[i];
				if((f1!=k[i]+1)&&(f2!=k[i]+1)){
					h=w[x]+w[y]+t[i][f1]+t[i][f2];
				}
				else if((f1==k[i]+1)&&(f2==k[i]+1)) continue;
				else if(f1!=k[i]+1) h+=w[x];
				else if(f2!=k[i]+1) h+=w[y];
			}
			printf("%lld\n",h);
		}
	}
	return 0;
}
