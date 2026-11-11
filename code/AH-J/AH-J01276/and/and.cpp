#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[200005];
void dg(long long x,long long y,long long z){
	if(z==m){
		ans=max(y,ans);
		return;
	}
	if(x==n+1) return;
	if(y<=ans) return;
	if(x>ans) dg(x+1,(y&a[x]),z+1);
	dg(x+1,y,z);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(long long i=1;i<=n;i++)scanf("%d",&a[i]);
	if(m==1)
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
	else if(m==2){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				ans=max(ans,a[i]&a[j]);
			}
	}
	else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++)
			ans&=a[i];
	}
	else if(n<=20)dg(1,(1<<25)-1,0);
	else{
		sort(a+1,a+n+1);
		ans=a[n-m+1];
	}
	printf("%lld",ans);
	return 0;
}
