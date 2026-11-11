#include<stdio.h>
int n,m,a[200005],r=-1,i,x,s,c,ans;
void out(int n){for(int i=30;i>=0;i--)printf("%d",n>>i&1);puts("");}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)scanf("%d",a+i);
	for(x=1<<30;x;x>>=1){
		for(s=r-1,c=0,i=0;i<n;i++)if((s&a[i])>=ans+x)s&=a[i],c++;
		if(c>=m)ans+=x;
		if(ans&&r==-1)r=ans<<1;
	}printf("%d",ans);
	return 0;
}
