#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long a[N];
int b[N],c[N],d[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;
	scanf("%d %d",&t,&t);
	while(t--){
		int n;
		long long m;
		bool v=true;
		scanf("%d %lld",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			b[i]=c[i]=d[i]=0;
		}
		if(n<4||a[n]-a[1]<=m){
			printf("0\n");
			continue;
		}
		for(int i=2;i<=n-1;i++){
			if(a[i]-a[i-1]!=a[i+1]-a[i]){
				v=false;
				break;
			}
		}
		if(v){
			long long d=a[2]-a[1];
			if(m<d*2)printf("0\n");
			else printf("%lld\n",max(0ll,n-m/d*2+1));
			continue;
		}
		for(int i=1;i<=n;i++){
			if(a[i]-a[1]<=m&&a[n]-a[i]<=m){
				v=true;
				break;
			}
		}
		for(int i=1,j=1;i<=n;i++){
			if(i>j)j=i;
			while(j<n&&a[j+1]-a[i]<=m)++j;
			b[i]=j;
		}
		for(int i=n,j=n;i;i--){
			if(i<j)j=i;
			while(j>1&&a[i]-a[j-1]<=m)--j;
			++c[j];
		}
		long long ans=0;
		if(v){
			for(int i=1;i<=n-3;i++){
				if(b[i]-1>i)ans+=c[b[i]-1];
			}
			printf("%lld",ans);
			continue;
		}
		for(int i=n,j=n;i;i--){
			if(i<j)j=i;
			while(j>1&&a[i]-a[j-1]<=m)--j;
			c[i]=j;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				d[1]=i;
				int cnt=1;
				while(d[cnt]<j){
					int x=d[cnt];
					if(b[x]==x){
						d[++cnt]=-1;
						break;
					}
					d[++cnt]=min(b[x],j);
				}
				if(d[cnt]==-1)continue;
				int p=0;
				for(int k=1;k<=cnt-2;k++){
					if(b[d[k]]==c[d[k+2]]+1)++p;
					else if(b[d[k]]>c[d[k+2]]+1)p=2;
				}
				if(p==1)++ans;
			}
		}
		printf("%lld",ans);
	}
	return 0;
}
