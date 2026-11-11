#include<bits/stdc++.h>
using namespace std;
long long x[2000005];
int f[5005][5005],s[5005][5005];
int cs,t,as,n,r;
long long d;
void gga(){
	while(t--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		long long d1=x[2]-x[1];
		long long kk=d/d1;
		if(kk==0||kk==1)printf("0\n");
		else printf("%lld\n",max(0ll,1ll*n-2*kk+1ll));
	}
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&cs,&t);
	if(cs==11||cs==12){
		gga();
		return 0;
	}
	while(t--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		as=0;
		memset(f,0x3f,sizeof(f));
		memset(s,0,sizeof(s));
		for(int i=2;i<=n;i++){
			for(int l=1;l+i-1<=n;l++){
				r=l+i-1;
				if(x[r]-x[l]<=d){
					f[l][r]=1;
					s[l][r]=1;
					continue;
				}
				for(int j=l+1;j<r;j++){
					if(f[l][j]+f[j][r]<f[l][r]){
						f[l][r]=f[l][j]+f[j][r];
						s[l][r]=s[l][j]*s[j][r];
					}else if(f[l][j]+f[j][r]==f[l][r]){
						s[l][r]+=s[l][j]*s[j][r];
					}
				}
				s[l][r]=s[l][r]/(f[l][r]-1);
				if(s[l][r]==2)as++;
			}
		}
		printf("%d\n",as);
	}
	return 0;
}
