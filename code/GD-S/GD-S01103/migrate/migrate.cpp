// T3_brute O(n^2)
#include<bits/stdc++.h>
#define int long long
using namespace std;
int id,T,n,k,a[2000005],ReachR[2000005],ans,dis[5005][5005],cnt[5005][5005];
int read(){
	char op=getchar();
	int num=0,f=1;
	while(!(op>='0'&&op<='9')){
		if(op=='-') f=-1;
		op=getchar();
	}
	while(op>='0'&&op<='9') num*=10,num+=(op-'0'),op=getchar();
	return num*f;
}
void write(int ans){
	if(ans>9) write(ans/10);
	putchar('0'+(ans%10));
}
void solve(){
	n=read(),k=read(),ans=0;
	for(int i=1;i<=n;i++) a[i]=read();
	if(n==1){
		puts("0");
		return;
	}
	if(id==11||id==12){
		if(a[2]-a[1]>=k) return puts("0"),void();
		int w=(k/(a[2]-a[1]));
		if(w==1||w==0) return puts("0"),void();
		write(max(n-2*w+1,0ll)),putchar('\n');
		return;
	}
	for(int i=1,j=0;i<=n;i++){
		j=max(j,i);
		while(j+1<=n&&a[j+1]-a[i]<=k) j++;
		ReachR[i]=j;
	}
	for(int i=1;i<=n;i++)
		dis[i][i]=0,cnt[i][i]=1;
	for(int len=2;len<=n;len++)
		for(int l=1;l+len-1<=n;l++){
			int r=l+len-1;
			if(ReachR[l]>=r){
				dis[l][r]=1,cnt[l][r]=1;
				continue;
			}
			cnt[l][r]=0,dis[l][r]=INT_MAX;
			for(int k=l+1;k<r;k++){
				if(dis[l][k]+dis[k][r]<dis[l][r]) dis[l][r]=dis[l][k]+dis[k][r],cnt[l][r]=cnt[l][k]*cnt[k][r];
				else if(dis[l][k]+dis[k][r]==dis[l][r]) cnt[l][r]+=cnt[l][k]*cnt[k][r];
				cnt[l][r]=min(cnt[l][r],3ll);
			}
			cnt[l][r]=min(cnt[l][r],3ll);
			ans+=(cnt[l][r]==2);
		}
	printf("%lld\n",ans);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&id,&T);
	while(T--)
		solve();
	return 0;
}
