#include<bits/stdc++.h>
int n,m,a[200002],c=1e9,k,i,l=1<<30,ans;
int main(){
	freopen("and.in","r",stdin),
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m),ans=INT_MAX;
	while(++i<=n)
		scanf("%d",a+i);
	while(c>m){
		for(c=0,k=l;c<m&&k;c<m?k>>=1:0)
			for(c=i=0;++i<=n;)
				a[i]&k?++c:0;
		if(c>=m){
			for(i=0;++i<=n;)
				if(!(a[i]&k)) a[i]=0;
			l=k>>1;
		}else l>>=1;
		if(k>=2) continue;
	}
	for(i=0;++i<=n;)
		a[i]?ans&=a[i]:0;
	printf("%d",ans>(1<<30)?0:ans);
}
