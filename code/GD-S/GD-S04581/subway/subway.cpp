#include<bits/stdc++.h>
using namespace std; 
long long n,m,d,q,jzt[114514],jxl[114514][514],xlt[514][514],wx[114514][500],s,e,ans,mi,mij,mm[2],b[514];
int ge(long long x,long long de){
	if(x==e){
		return de;
	}
	long long mii=0;
	for(long long p=1;p<=n;p++){
		if(p!=x&&xlt[x][p]!=0&&!b[p]){
			b[p]=1;
			long long jg=ge(p,de+xlt[x][p]);
			b[p]=0;
			if(mii){
				mii=min(mii,jg);
			}
			else{
				mii=jg;
			}
		}
	}
	return mii;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(jxl,0,sizeof(jxl));
	memset(xlt,0,sizeof(xlt));
	memset(wx,0,sizeof(wx));
	memset(jzt,0,sizeof(jzt));
	scanf("%lld %lld %lld %lld %lld",&n,&n,&m,&d,&q);
	for(long long i=1;i<=m;i++){
		scanf("%lld",&jzt[i]);
	}
	for(long long j=1;j<=n;j++){
		long long t,x,y;
		scanf("%lld",&t);
		for(long long i=1;i<=t;i++){
			scanf("%lld %lld",&x,&y);
			jxl[x][j]=y;
			wx[x][++wx[x][0]]=j;
		}
	}
	for(long long i=1;i<=m;i++){
		for(long long j=1;j<=wx[i][0]-1;j++){
			for(long long k=1+j;k<=wx[i][0];k++){
				long long J=wx[i][j],K=wx[i][k];
				long long ttt=jxl[i][J]+jxl[i][K];
				if(xlt[J][K]==0){
					xlt[J][K]=ttt;
					xlt[K][J]=ttt;
				}
				else{
					xlt[J][K]=min(xlt[J][K],ttt);
					xlt[K][J]=min(xlt[K][J],ttt);
				}
			}
		}
	}
	for(long long i=1;i<=n-1;i++){
		for(long long j=i+1;j<=n;j++){
			s=i;
			e=j;
			b[i]=1;
			long long ft=ge(s,0);
			xlt[i][j]=ft;
			xlt[j][i]=ft;
			b[i]=0;
		}
	}
	for(long long I=0;I<q;I++){
		scanf("%lld %lld",&s,&e);
		ans=jzt[s]+jzt[e];
		mi=0;
		mij=0;
		bool pd=1;
		if(s>e){
			long long tt=s;
			s=e;
			e=tt;
		}
		if(s==e){
			printf("0\n");
			continue;
		}
		for(long long i=1;i<=wx[s][0];i++){
			long long c=wx[s][i];
			if(jxl[e][c]){
				pd=0;
				if(mi==0){
					mi=jxl[s][c]+jxl[e][c];
				}
				else{
					mi=min(mi,jxl[s][c]+jxl[e][c]);
				}
			}
		}
		if(pd){
			for(long long i=1;i<=wx[s][0];i++){
				long long c1=wx[s][i];
				for(long long j=1;j<=wx[e][0];j++){
					long long c2=wx[e][j];
					if(mi){
						long long x=jxl[s][c1]+jxl[e][c2]+xlt[c1][c2];
						if(mi>x){
							mi=x;
							mij=jxl[s][c1]+jxl[e][c2];
							mm[0]=c1;
							mm[1]=c2;
						}
					}
					else{
						mi=jxl[s][c1]+jxl[e][c2]+xlt[c1][c2];
						mij=jxl[s][c1]+jxl[e][c2];
						mm[0]=c1;
						mm[1]=c2;
					}
				}
			}
		}
		printf("%lld\n",ans+mi);
	}
}
