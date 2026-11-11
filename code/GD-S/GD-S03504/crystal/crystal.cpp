#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m,a[N],ans;
bool pianfen=1;
bool ppianfen=1;
int w[N],nn,b[N]; 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
		pianfen=pianfen&&(a[i]-a[i-1]==a[i-1]-a[i-2]),
		ppianfen=ppianfen&&(abs(a[i])<=100);
	if(pianfen){
		int d=a[2]-a[1];
		for(int i=0;i<n&&m>0;i++)
			m-=i*d,
			ans+=(m>=0);
		return printf("%lld",ans),0;
	}
	if(ppianfen){
		for(int i=1;i<=n;i++){
			a[i]+=4000;
			if(!w[a[i]])
				b[++nn]=a[i];
			w[a[i]]++;
		}
		for(int i=1;i<=nn;i++){
			int cnt=w[b[i]],tmp=m;
			for(int j=i-1;j>=1&&tmp>0;j--)
				tmp-=(b[i]-b[j])*w[b[j]],
				cnt+=(tmp>=0?w[b[j]]:min((tmp+(b[i]-b[j])*w[b[j]])/(b[i]-b[j]),b[j]));
			ans=max(ans,cnt);
		}
		return printf("%lld",ans),0;
	}
	for(int i=1;i<=n;i++){
		int cnt=1,tmp=m;
		for(int j=i-1;j>=1&&tmp>0;j--)
			tmp-=a[i]-a[j],
			cnt+=(tmp>=0);
		ans=max(ans,cnt);
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
