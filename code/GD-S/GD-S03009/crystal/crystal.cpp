#include<bits/stdc++.h>
using namespace std;
int n,j=1;
long long len=1,ans,cnt,m;
long long a[500010],b[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		len++;
		cnt+=(len-1)*(a[i]-a[i-1]);
		while(cnt>m){
			cnt-=(a[i]-a[j]);
			j++;
			len--;
		}
		ans=max(len,ans);
	}
	printf("%lld",ans);
	return 0;
}
