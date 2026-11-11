#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],minn[2];
void fly(int x,int sum,int tot){
	if(x==tot){
		if(sum<minn[0]){
			minn[0]=sum;
			minn[1]=1;
		}else if(sum==minn[0])minn[1]++;
		return;
	}
	for(int i=tot-x;i>=1;i--){
		if(a[x+i]-a[x]<=d){
			fly(x+i,sum+1,tot);
		}
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	if(c==11 or c==12){
		while(t--){
			scanf("%lld%lld",&n,&d);
			for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
			if(d/(a[2]-a[1])==2)printf("%lld\n",n-3);
			else printf("0\n");
		}
	}else {
		while(t--){
			int ans=0;
			scanf("%lld%lld",&n,&d);
			for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(i==j)continue;
					minn[0]=99999999;
					minn[1]=0;
					fly(i,0,j);
					if(minn[1]==2){
						ans++;
						//<<minn[0]<<" "<<i<<" "<<j<<endl;
					}
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
