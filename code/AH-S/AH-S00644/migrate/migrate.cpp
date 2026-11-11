#include <bits/stdc++.h>
using namespace std;
const long long N=2e6+5;
long long n,d,a[N],c,t,d1,ans;
bool work(int u,int v){
	if ((u-v)<=2)
		return 0;
	for (int i=u;i<=v;i++){
		if ((a[i]-a[i-1])>d)
			return 0;
	}
	return 1;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf ("%lld%lld",&c,&t);
	if (c==11||c==12){
		while (t--){
			long long ans=0;
			scanf ("%lld%lld",&n,&d);
			for (int i=1;i<=n;i++)
				scanf ("%lld",&a[i]);
			if ((a[2]-a[1])>d)
				printf ("0\n");
			else{
				d1=a[2]-a[1];
				d/=d1;
				d1=d;
				d/=2;
				ans=n-(2*d1+1-d)+1;
				printf ("%lld\n",ans);
			}	
		}
	}
	else{
		while (t--){
			long long ans=0;
			scanf ("%lld%lld",&n,&d);
			for (int i=1;i<=n;i++)
				scanf ("%lld",&a[i]);
			for (int i=1;i<=n;i++){
				for (int j=i+1;j<=n;j++){
					if (work(i,j))
						ans++;
				}
			}
			printf ("%d\n",ans);
		}
	}
	return 0;
}
