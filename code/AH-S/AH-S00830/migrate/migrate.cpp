#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int a[N],b[N],cf[N],cb[N];
int read(){
	int f=1,x=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+(c^48),c=getchar();
	return f*x;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	int c=read(),t=read();
	while(t--){
		int n=read(),m=read(),ans=0;
		for(int i=1;i<=n;i++) a[i]=read();
		sort(a+1,a+1+n);
		b[1]=upper_bound(a+1,a+1+n,a[1]+m)-a;
		for(int i=2,j=b[1];i<=n;i++){
			if(a[i]+m<a[j]) b[i]=j;
			else{
				while(j<=n&&a[i]+m>=a[j]) j++;
				b[i]=j;
			}
		}
		for(int i=1;i<=n;i++) 
			cb[i]=b[i]-i-1,cf[i]=a+i-lower_bound(a+1,a+1+n,a[i]-m);
		for(int i=1;i<=n;i++){
			if(b[i]>n) break;
			if(b[i]-i<=2) continue;
			for(int j=b[b[i]-3]+1;j<=b[b[i]-2];j++) ans+=cf[i]*cb[j];
			ans+=b[b[i]-2]-b[b[i]-3];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
5 3
-3 0 2 3 4
*/
