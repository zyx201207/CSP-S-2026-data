#include<bits/stdc++.h>
using namespace std;
const long long inf=1000000000000000001ll;
long long c,n,m,d,q,w[500010],k[510],b[500010][21][2],cnt[500010],tt[510][510],et;
int ts[510][500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(long long i=1;i<=m;i++){
		scanf("%lld",w+i);
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			tt[j][i]=inf;
		}
		tt[i][i]=0;
		scanf("%lld",k+i);
		for(long long j=1,tmpa,tmpt;j<=k[i];j++){
			scanf("%lld%lld",&tmpa,&tmpt);
			ts[i][tmpa]=tmpt;
			b[tmpa][++cnt[tmpa]][0]=i;
			b[tmpa][cnt[tmpa]][1]=tmpt;
			for(long long l=1;l<cnt[tmpa];l++){
				tt[b[tmpa][l][0]][i]=min(tt[b[tmpa][l][0]][i],ts[b[tmpa][l][0]][tmpa]+tmpt);
			}
		}
	}
	for(long long i=2;i<=n;i++){
		for(long long j=1;j<i;j++){
			tt[i][j]=tt[j][i];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int l=1;l<j;l++){
				tt[j][l]=tt[l][j]=min(tt[j][l],tt[j][i]+tt[i][l]);
			}
		}
	}
	
	
//		cout<<"\n";
//		cout<<"\n";
//	for(long long i=1;i<=n;i++){
//		for(long long j=1;j<=n;j++){
//			cout<<tt[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
//		cout<<"\n";


	for(long long st,ed,ans;q--;){
		scanf("%lld%lld",&st,&ed);
		ans=inf;
		for(int i=1;i<=cnt[st];i++){
			for(int j=1;j<=cnt[ed];j++){
//				printf("ans = min ( %lld",ans);
				ans=min(ans,w[st]+w[ed]+b[st][i][1]+b[ed][j][1]+tt[b[st][i][0]][b[ed][j][0]]);
//				printf(" , %lld + %lld + %lld + %lld + %lld ) ;\n",w[st],w[ed],b[st][i][1],b[ed][j][1],tt[b[st][i][0]][b[ed][j][0]]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
