#include<bits/stdc++.h>
using namespace std;
int n,m,ma,a[200010],pre[2010],nxt[2010];
void dfs(int step,int sum,int cnt){
	if(step==n+1){
		ma=max(ma,sum);
		return;
	}
	if(n-step>=m-cnt)
		dfs(step+1,sum,cnt);
	if(cnt<m)
		dfs(step+1,sum&a[step],cnt+1);
	return;
}
int main() {
#ifndef DEBUG_
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
#endif
	scanf("%d%d",&n,&m);
	if(n<=20){
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		for(int i=1;i<=n;i++)
			dfs(i+1,a[i],1);
		printf("%d",ma);
		return 0;
	}
	if(n<=2000){
		if(m==1){
			int ma=0;
			for(int i=1;i<=n;i++){
				scanf("%d",a+i);
				ma=max(ma,a[i]);
			}
			printf("%d",ma);
			return 0;
		}
		if(m==n){
			int sum;
			scanf("%d",&sum);
			for(int i=2;i<=n;i++){
				scanf("%d",a+i);
				sum&=a[i];
			}
			printf("%d",sum);
			return 0;
		}
		if(m==2){
			int ans=0;
			for(int i=1;i<=n;i++)
				scanf("%d",a+i);
			for(int i=1;i<n;i++)
				for(int j=i+1;j<=n;j++)
					ans=max(ans,(a[i]&a[j]));
			printf("%d",ans);
			return 0;
		}
		return 0;
	}
	if(n<=200000){
		if(m==2){
			for(int i=1;i<=n;i++){
				scanf("%d",a+i);
				pre[i]=(i==1?a[i]:(pre[i-1]&a[i]));
			}
			for(int i=n;i;i--)
				nxt[i]=(i==n?a[i]:(nxt[i+1]&a[i]));
			int ans=max(pre[n-1],nxt[2]);
			for(int i=2;i<n;i++)
				ans=max(ans,(pre[i-1]&nxt[i+1]));
			printf("%d",ans);
			return 0; 
		}
		bool flagA=true,flagB=true,flag4=true,flag10=true;
		if((1<<((int)log2(n)))!=n)
			flagB=false;
		for(int i=1;i<=n;i++){
			scanf("%d",a+i);
			if(a[i]!=i-1)
				flagB=false;
			if((1<<((int)log2(a[i]+1)))-1!=a[i])
				flagB=false;
			if(a[i]>4)
				flag4=false;
			if(a[i]>1024)
				flag10=false;
		}
		if(flagA){
			sort(a+1,a+n+1,greater<int>());
			printf("%d",a[m]);
			return 0;
		}
		if(flagB){
			
		}
		if(flag4){
			int tong[5]={};
			for(int i=1;i<=n;i++)
				tong[a[i]]++;
			if(tong[4]>m)
				printf("4");
			else if(tong[4]+tong[3]>m)
				printf("3");
			else if(tong[4]+tong[3]+tong[2]>m)
				printf("2");
			else
				printf("1");
			return 0;
		}
		if(flag10){
			
		}
	}
	return 0;
}
//保大数位


