//黄烨 毕节七星关东辰实验学校  GZ-S00044 
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m;
int a[500010];
int cnt[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int t=(a[1]+a[n])/2;
	for(int i=1;i<=n;i++){
		cnt[i]=abs(a[i]-t);
	} 
	int ans=0;
	sort(cnt+1,cnt+1+n);
	for(int i=1;i<=n;i++){
		cnt[i]+=cnt[i-1];
		if(cnt[i]<=m){
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
