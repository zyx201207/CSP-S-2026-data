#include<bits/stdc++.h>
using namespace std;
long long c,T,n,d,x[2000009],ymy=0,cnt,ans;
void DFS(long long L,long long R,long long sum){
	if(L==R){
		if(ans>sum) ans=sum,cnt=0;
		else if(ans==sum) cnt++;
		return ;
	}
	for(int i=L+1;i<=R;i++){
		if(x[i]-x[L]>d) break;
		DFS(i,R,sum+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&c,&T);
	while(T--){
		scanf("%lld %lld",&n,&d),ymy=0;
		for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
		if(c==11||c==12){
			long long dd=abs(x[2]-x[1]),w=d/dd;
			if(w>=2) ymy=max(0ll,n-2*w+1);
			printf("%lld\n",ymy);continue;
		}
		if(c==13||c==14){
			long long ww=0,now=0;
			for(int i=1;i<=n;i++)
				if(x[1]+d>=x[i]&&x[i]+d>=x[n]){ww=i;break;}
			now=ww;
			for(int i=1,j=ww+1;i<ww&&j<=n;){
				if(x[j]-x[i]<=d){now=j,j++;continue;}
				if(now-ww>1){i++;continue;}
				if((now-ww==1)&&(x[ww-1]+d>=x[j])){i++;continue;}
				if(now==ww){
					if(i+2>ww&&x[ww-1]+d<x[j]){i++;continue;}
					if(i+2<=ww&&x[ww-2]+d>=x[j]){i++;continue;}
				}
				ymy++,i++;
			}
			printf("%lld\n",ymy);continue;
		}
		for(int i=1;i<=n;i++)
			for(int j=i+3;j<=n;j++){
				cnt=0,ans=j-i+10;DFS(i,j,0);
				if(cnt==1) ymy++;
			}
		printf("%lld\n",ymy);
	}
	return 0;
}
