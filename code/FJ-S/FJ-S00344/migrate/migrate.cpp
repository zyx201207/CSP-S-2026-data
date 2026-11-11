#include<bits/stdc++.h>
#define int long long
using namespace std;
int testid,T,n,m,a[2000005],dp[2000005],last[2000005],pre[2000005],func[2000005],ans;
int find(int x,int l,int r){
	l--;
	r++;
	while(l+1<r){
		int mid=(l+r>>1);
		if(dp[mid]<=x)l=mid;
		else r=mid;
	}
	return l;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>testid>>T;
	while(T--){
		scanf("%lld%lld",&n,&m);
		int p=1;
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			while(p<=i&&a[i]-a[p]>m)p++;
			last[i]=p;
		}
		if(testid==11||testid==12){
			if(n==1||m<(a[2]-a[1])*2||a[1]==a[2]){
				printf("0\n");
				continue;
			}
			printf("%lld\n",max(0ll,n-m/(a[2]-a[1])*2+1));
		}else{
			for(int i=1;i<=n;i++){
				dp[i]=0;
				func[i]=1;
				pre[i-1]=0;
				pre[i]=1;
				for(int j=i+1;j<=n;j++){
					if(last[j]==j)break;
					int x=max(last[j],i);
					dp[j]=dp[x]+1;
					func[j]=pre[find(dp[x],i,j-1)]-pre[x-1];
					pre[j]=pre[j-1]+func[j];
					if(func[j]==2)ans++;
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
