#include<bits/stdc++.h>
using namespace std;
long long a[2000010],rnum[2000010],inum[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,h,n,m;
	int i,j,k,x=0;
	scanf("%d%d",&c,&t);
	rnum[1]=0;inum[1]=0;
	for(h=1;h<=t;++h){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;++i){
			scanf("%lld",&a[i]);
		}x=0;
		for(i=2;i<=n;++i){
			rnum[i]=0;
			inum[i]=-1;
			for(j=i-1;a[j]>=a[i]-m&&j>=1;--j){
				if(inum[i]==-1){
					inum[i]=inum[j]+1;
					rnum[i]++;
				}else if(inum[j]+1==inum[i]){
					rnum[i]++;
				}else if(inum[j]+1<inum[i]){
					inum[i]=inum[j]+1;
					rnum[i]=1;
				}

			}
			
			if(rnum[i]==2){
				x++;
			}
			if(i>2&&a[i-1]>=a[i+1]-m&&a[i-2]<a[i+1]-m){
				rnum[i]=1;
				inum[i]=1;
			}
		}
		printf("%d\n",x);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

