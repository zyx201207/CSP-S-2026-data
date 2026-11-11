#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int N=5e5;
int n,ans=1;
ll m,a[N+5];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
	}
	sort(a+1,a+1+n);
	int l=1;
	ll sum=0;
	for(int r=2;r<=n;r++){
		sum+=(a[r]-a[r-1])*(r-l);
		if(sum<=m){
			ans=max(ans,r-l+1);
		}else{
			while(sum>m){
				sum-=a[r]-a[l];
				l++;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
