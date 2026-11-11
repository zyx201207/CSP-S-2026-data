#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL n,k,a[500010],b[500010],de,id=0,now,ans=0;
map<LL,LL> cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&now);
		if(!cnt[now]){
			a[++id]=now;
		}
		cnt[now]++;
	}
	sort(a+1,a+id+1);
	for(int i=1;i<=id;i++){
		b[i]=b[i-1]+cnt[a[i]];
	}
	for(int i=1;i<=id;i++){
		ans=max(ans,cnt[a[i]]);
		de=0;
		for(int j=i-1;j>=0;j--){
			if(!j){
				ans=max(ans,b[i]);
				break;
			}
			de+=(a[i]-a[j])*cnt[a[j]];
			if(de>k){
				de-=(a[i]-a[j])*cnt[a[j]];
				ans=max(ans,b[i]-b[j]+(k-de)/(a[i]-a[j]));
				break;
			}
			ans=max(ans,b[i]-b[j]);
		}
	}
	printf("%lld",ans);
	return 0;
}

