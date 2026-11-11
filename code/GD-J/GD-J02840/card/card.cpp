#include<stdio.h>
int n,m,a[500005],A=1,cnt[300005],p[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",a+i),p[a[i]]=i+1,i>0?A&=a[i]>=a[i-1]:0;
	if(A){for(int i=1;i<=m;i++)printf("%d ",p[i]);}
	return 0;
}

