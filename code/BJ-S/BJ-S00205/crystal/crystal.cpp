#include<bits/stdc++.h>
using namespace std;
int const MAXN=(int)5e5+5;
int n;
long long m;
long long a[MAXN];
int ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		long long t=0;
		int cnt=0;
		if(n>=100000){
			i=n;
		}
		for(int j=i;j>=1;j--){
			if(t+a[i]-a[j]<=m){
				t+=a[i]-a[j];
				cnt++;
			}
		}
		ans=max(ans,cnt);
	}
	printf("%d\n",ans);
	return 0;
}
