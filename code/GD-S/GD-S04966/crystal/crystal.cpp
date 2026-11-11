#include <bits/stdc++.h>
using namespace std;
int n,ans=1,t=1;
long long m,a[500010],c[500010],l;
void solve(int l,int r){
	if(l==r)
		return;
	int p=l,q=r,x=(l+r)/2,y=(l+r)/2+1,t=0;
	solve(p,x);
	solve(y,q);
	while(p<=x&&y<=q){
		if(a[p]<=a[y])
			c[++t]=a[p++];
		else
			c[++t]=a[y++];
	}
	while(p<=x)
		c[++t]=a[p++];
	while(y<=q)
		c[++t]=a[y++];
	for(int i=l;i<=r;i++)
		a[i]=c[i-l+1];
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	solve(1,n);
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1])
			t++;
		else{
			l=m;
			ans=max(ans,t);
			t=1;
			for(int j=i-1;j>0;j--){
				if(l<a[i]-a[j])
					break;
				l+=a[j]-a[i],t++;
			}
		} 
		ans=max(ans,t);
	}
	printf("%d",ans);
	return 0;
} 
