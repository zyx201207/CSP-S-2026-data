#include<cstdio>
int n,m,a[500005],x,tim[500005]; 
bool f[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
	  	  if(f[a[j]]) {
	  		x=j;
	  		do{
	  			x--;
				f[a[x]]=0;
			}while(a[x]!=a[j]);
	    }
        	f[a[j]]=1;
	  }
	  for(int j=1;j<=m;j++) if(f[j]) tim[j]++;
	  for(int i=1;i<=m;i++) f[i]=0;
	}
      for(int i=1;i<=m;i++) printf("%d ",tim[i]);  
	return 0;
} 
