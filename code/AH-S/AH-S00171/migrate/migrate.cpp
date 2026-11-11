#include<bits/stdc++.h>
using namespace std;
int c,T,n,res,rlen;
long long d,a[2000005];
void dfs(int k,int ed,int len){
	if(k==ed){
		if(len<rlen)  res=0,rlen=len;
		res++;
		return;
	}
	for(int i=k+1;a[i]-a[k]<=d && i<=ed;i++){
		dfs(i,ed,len+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)  scanf("%lld",&a[i]);
//		if(c==11 || c==12){
//			if(a[2]-a[1]<=d && n>=3)  printf("%d\n",n-2);
//			else  printf("0\n");
//		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				res=0,rlen=INT_MAX; dfs(i,j,0);
				if(res==2)  ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
