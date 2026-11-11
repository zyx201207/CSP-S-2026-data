#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
int n;
long long m;
long long a[MAXN];
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	int l=1;
	long long Nowsum=0;
	for(int i=1;i<=n;i++){
		Nowsum+=(a[i]-a[i-1])*(i-l);
		while(Nowsum>m){
			Nowsum-=(a[i]-a[l]);
			l++;
		}
		ans=max(i-l+1,ans);
	}
	printf("%d",ans);
	return 0;
}

