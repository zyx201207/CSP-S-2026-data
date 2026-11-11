#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,a[2000005];
//0~10
int f[2005],g[2005];
void work1(){
	long long ans=0;
	for(int i=2;i<=n;i++){
		int z=i;
		g[z]=1;
		for(int j=i-1;j>=1;j--){
			while(a[z]-a[j]>d) z--;
			if(z==j) break;
			f[j]=f[z]+1;
			int sum=g[z];
			if(z>j+1&&f[z-1]==f[z]) sum+=g[z-1];
			if(z>j+2&&f[z-2]==f[z]) sum+=g[z-2];
			if(sum>=3) sum=3;
			g[j]=sum;
			if(g[j]==2) ans++;
		}
	}
	printf("%lld\n",ans);	
}
//11~12
void work2(){
	if(n==1){
		printf("0\n");
		return;
	}
	long long c=a[2]-a[1];
	if(c>d){
		printf("0\n");
		return;
	}
	long long sum=d/c;
	if(sum>=n) sum=n-1;
	if(sum==1||2*sum>n){
		printf("0\n");
		return;
	}
	printf("%lld\n",1ll*n-2*sum+1);
}
//13-18
int lst[2000005];
int lx[55],rx[55],len;
void work3(){
	lst[1]=1;
	for(int i=2;i<=n;i++){
		lst[i]=lst[i-1];
		while(a[i]-a[lst[i]]>d) lst[i]++;
	}
	long long ans=0;
	for(int i=2;i<=n;i++){
		if(i==lst[i]) continue;
		len=0;
		int now=i;
		while(now!=lst[now]){
			lx[++len]=lst[now];rx[len]=now-1;
			now=lst[now];
		}
		int mn3=n+1,mx1=rx[1];
		for(int j=2;j<=len;j++){
			int minn=n+1,maxn=0;
			if(mn3!=n+1) minn=min(minn,lst[mn3]);
			if(lx[j-1]<rx[j-1]&&mx1<lx[j-1]+1) minn=min(minn,lst[lx[j-1]+1]);
			if(lx[j-1]+1<rx[j-1]) minn=min(minn,lst[lx[j-1]+2]);
			if(mx1>=lx[j-1]){
				if(lx[j-1]==rx[j-1]) maxn=rx[j];
				else maxn=lst[lx[j-1]+1]-1;
			}
			ans=ans+min(minn,rx[j]+1)-max(maxn,lx[j]-1)-1;
			if(minn>=rx[j]+1) minn=n+1;
			if(maxn<=lx[j]-1) maxn=0;
			mn3=minn;mx1=maxn;
		}
	}
	printf("%lld\n",ans);
}
int main(){	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		if(c==0) work1();
		else if(c>=1&&c<=10) work1();
		else if(c>=11&&c<=12) work2();
		else if(c>=13&&c<=18) work3();
		else work1();
	}
	return 0;
}
