#include<cstdio>
int n,m,max,a[200005],ans; 
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) 
	  scanf("%d",&a[i]);
	if(m==1) {
	    for(int i=1;i<=n;i++) 
		  if(a[i]>max) max=a[i];
		printf("%d",max);
	}
	else if(m==2) {
		for(int i=1;i<n;i++)
		  for(int j=i+1;j<=n;j++){
		  	if((a[i]&a[j])>ans) ans=(a[i]&a[j]);
		  }
	    printf("%d",ans);
	}
	else if(m==n) {
		ans=a[1];
		for(int i=1;i<=n;i++) 
		  ans&=a[i];
		printf("%d",ans);
	}
	return 0;
} 
