#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
long long n,m,a[maxn],cnt=1,s[maxn],ans=1,t;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=a[i];
	t=m;
	for(int i=2;i<=n;i++){
		m=t;
		cnt=0;
		for(int j=1;j<=n;j++) a[j]=s[j];
		for(int j=i-1;j>=1;j--){
			if(a[j]<a[i]&&a[i]-a[j]<=m){
				m-=(a[i]-a[j]);
				a[j]=a[i];
			}
			else if(a[i]-a[j]>m){
				a[j]+=m;
				break;
			} 
			if(m<=0) break;
		}
		for(int j=1;j<=i;j++){
			if(a[j]==a[i]) cnt++;
		}
		ans=max(cnt,ans);
	}
	printf("%lld",ans);
	return 0;
}
