#include<bits/stdc++.h>
using namespace std;
int a[200005][31];
int b[200005],c[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,i,j,m,k,ans=0,p,sum,q,mi=1;
	scanf("%d %d",&n,&m);
	memset(a,0,sizeof(a));
	for(i=1;i<=n;i++){
		scanf("%d",&a[i][0]);
		k=a[i][0],j=1;
		while(k>=1){
			a[i][j++]=k%2;
			k=k/2;
		}
	}
	for(i=1;i<=30;i++)
		mi=mi*2;
	for(i=1;i<=n;i++)
		c[i]=i;
	p=n;
	for(i=30;i>=1;i--){
		mi=mi/2;
		memset(b,0,sizeof(b));
		sum=k=0;
		for(j=1;j<=p;j++)
			if(a[c[j]][i]==1)
				sum++,b[++k]=c[j];
		if(sum>=m){
			p=k;
			for(j=1;j<=k;j++)
				c[j]=b[j];
			ans+=mi;
		}
	}
	printf("%d",ans);
	return 0;
}
