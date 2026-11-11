#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t,n;
ll x[2000006],d,b[2000006],ans,k,sh[2000005],bb[2000005];
bool b2[2000005];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		memset(b,0,sizeof(b));
		int inp;
		for(int i=1;i<=d+1;i++)b[i]=1;
		for(int i=d+2;i<=2000006;i++){
			int mi=INT_MAX;
			memset(bb,0,sizeof(bb));
			k=0;
			for(int j=d;j>=1;j--){
				//k=0;
				int len;
				bool bo=0,yu;
				if(i%j){
					bo=1;
					yu=i%j;
					len=(i/j)+1;
				}
				else len=(i/j);
				if(len>mi)break;
				mi=len;
				sh[++k]=j;
				if(bo)sh[++k]=yu;
			}
			for(int j=1;j<=k;j++){
				if(!bb[sh[j]]){
				
				b[i]+=b[i-sh[j]];
				//cout<<sh[j]<<' '<<b[i-sh[j]]<<' '<<b[i]<<endl;
				bb[sh[j]]=1;
				sh[j]=i-sh[j];
			}
			}
			if(b[i]==2){
				inp=i;
			break;	
			}
		}
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
			b2[x[i]]=1;
		}
		for(int i=1;i<=n;i++){
			bool b3=1;
			for(int j=1;j<=k;j++){
				if(!b2[x[i]+sh[j]-1]){
				b3=0;
				break;	
				}
			}
		
		if(b3&&b2[x[i]+inp-1])ans++;
}

		printf("%lld",ans+1);
	}
	return 0;
}
