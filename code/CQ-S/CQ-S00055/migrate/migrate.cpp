#include<bits/stdc++.h>
using namespace std;
int c,t,n,r[2000005],l[2000005];
long long d,a[2000005],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		long long mi=1e18,mx=-1e18;
		for(int i=1;i<=n;i++){
			scanf("%lld",a+i);
			mi=min(mi,a[i]);
			mx=max(mx,a[i]);
			l[i]=n+1;
			r[i]=i;
		}
		if(c==11||c==12){
			d=d/(a[2]-a[1]);
			printf("%lld\n",max(1ll*n-(d<<1)+1,0ll));
		}else if(mx-mi<=d)puts("0");
		else {
			for(int i=1;i<n;i++)
				for(int j=i+1;j<=n;j++)
					if(a[j]-a[i]<=d){
						r[i]=j;
						l[j]=min(i,l[j]);
					}else break;
			vector<int>x,y,z;
			for(int i=1;i<n;i++)
				for(int j=i+1;j<=n;j++){
					int w=i;
					while(w<j){
						if(r[w]==w)break;
						x.push_back(w);
						w=r[w];
					}
					if(r[w]==w&&w<j)break;
					w=j;
					while(w>i){
						y.push_back(w);
						w=l[w];
					}
					w=i;
					while(w<=j){
						if(r[w]-1==w){
							z.clear();
							break;
						}
						z.push_back(w);
						w=r[w]-1;
					}
					if(x.size()==y.size()&&z.size()!=x.size()){
						x.push_back(j);
						y.push_back(i);
						w=x.size();
						for(int k=0;k<w;k++)
							if(x[k]!=y[w-k-1]){
								ans++;
								break;
							}
					}
					x.clear();
					y.clear();
					z.clear();
				}
		}
		printf("%lld\n",ans);
		ans=0;
	}
	return 0;
}
