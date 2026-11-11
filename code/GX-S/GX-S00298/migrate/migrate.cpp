#include<cstdio>
char buf[1<<24]={},*p1=buf,*p2=buf,ch;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<24,stdin),p1==p2)?EOF:*p1++)
#define isD(ch) (48<=ch&&ch<=57)
long long read(){
	long long num=0;
	bool f=0;
	ch=gc();
	while(!isD(ch)){
		if(ch=='-') f=1;
		ch=gc();
	}
	if(f){
		while(isD(ch)) num=(num<<3)+(num<<1)-(ch^48),ch=gc();
		return num;
	}
	while(isD(ch)) num=(num<<3)+(num<<1)+(ch^48),ch=gc();
	return num;
}
int c,t,n;
long long d,x[2114514]={},ans;
int findR(long long v){
	int L=1,R=n,mid,ans=0;
	while(L<=R){
		mid=(L+R)>>1;
		if(x[mid]<v) ans=mid,L=mid+1;
		else R=mid-1;
	}
	return ans;
}
int findL(long long v){
	int L=1,R=n,mid,ans=0;
	while(L<=R){
		mid=(L+R)>>1;
		if(x[mid]>=v) ans=mid,R=mid-1;
		else L=mid+1;
	}
	return ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),d=read(),ans=0;
		for(int i=1;i<=n;i++) x[i]=read();
		if(n<=5000){
			int f[n+1][n+1]={},g[n+1][n+1]={};
			for(int i=1;i<=n;i++) g[i][i]=1;
			for(int i=2;i<=n;i++) for(int j=1;j<i;j++){
				f[j][i]=114514;
				for(int k=i-1;k>=j;k--){
					if(x[i]-x[k]>d) break;
					if(f[j][k]+1<f[j][i]) f[j][i]=f[j][k]+1,g[j][i]=0;
					if(f[j][k]+1==f[j][i]) g[j][i]+=g[j][k];
				}
				if(g[j][i]==2) ans++;
			}
		}else if(13<=c and c<=14){
			for(int i=2,xl,xr;i<=n;i++){
				xr=findR(x[i]-d);
				if(xr) xl=findL(xr-d),ans+=(xr-xl+1);
			}
		}else if(11<=c and c<=12){
			long long dx=x[2]-x[1],k=d/dx;
			ans=(n>=2*k?n-2*k+1:0);
		}
		printf("%lld",ans);
		if(t) printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
