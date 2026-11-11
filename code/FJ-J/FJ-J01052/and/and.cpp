#include<stdio.h>
#include<algorithm>
int n,m,a[200001],q[200001]={(1<<30)-1},h[200001],s,i;
void dfs(int x,int sum,int chs){
	if(chs>m)return;
	if(x>n){
		if(sum>s&&chs==m)s=sum;
		return;
	}
	dfs(x+1,sum,chs);
	dfs(x+1,sum&a[x],chs+1);}
void end(){
	printf("%d",s);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	if(n<=20){
		dfs(1,(1<<30)-1,0);
		end();return 0;
	}
	if(m==n-1){
		for(int i=1;i<n;++i)q[i]=q[i-1]&a[i];
		h[n]=a[n];
		for(int i=n-1;i;--i)h[i]=h[i+1]&a[i];
		for(int i=2;i<=n;++i)if(h[i]&q[i-2]>s)s=h[i]&q[i-2];
		end();return 0;
	}
	if(m==n){
		s=(1<<30)-1;
		for(int i=1;i<=n;++i)s&=a[i];
		end();return 0;
	}
	if(m==1){
		for(int i=1;i<=n;++i)if(a[i]>s)s=a[i];
		end();return 0;
	}
	if(m==2){
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				if(a[i]&a[j]>s)s=a[i]&a[j];
		end();return 0;
	}
	std::sort(a+1,a+n+1);
	s=a[n-m+1];
	for(int i=n-m+2;i<=n;++i)s&=a[i];
	end();return 0;
}
