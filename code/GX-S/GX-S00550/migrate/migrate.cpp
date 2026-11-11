#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
const long long inf=1e9;
int c,t;
int n;
long long d;
long long a[N];
struct op{
	int w,num;
}f[N];
int ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		ans=0;
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)f[j].num=0;
			for(int j=1;j<=n;j++)f[j].w=inf;
			f[i].w=0;
			f[i].num=1;
			for(int j=i;j<=n;j++){
				for(int k=j;k>=i;k--){
					if(a[j]-a[k]<=d){
						if(f[j].w>f[k].w+1){
							f[j].w=f[k].w+1;
							f[j].num=1;
						}else if(f[j].w==f[k].w+1)f[j].num+=f[k].num;
					}else break;
				}
			}
			//if(i==1)for(int j=1;j<=n;j++)cout<<f[j].num<<" ";
			for(int j=i;j<=n;j++)if(f[j].num==2)ans++;
		}
	printf("%d\n",ans);
	}
	
	return 0;
}
