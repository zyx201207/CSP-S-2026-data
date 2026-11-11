#include<bits/stdc++.h>
using namespace std;
int a[50010];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out","w", stdout);
	int n;
	long long m;
	scanf ("%d%lld", &n, &m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	long long ans=0;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long long sum=0,t=0;
		for (int j=i;j>=1;j--){
			if(sum+a[i]-a[j]<=m){
				t++;
				sum+=a[i]-a[j];
			} 
		}
		ans = max(ans,t);
	}
	printf("%lld",ans);
	return 0;
}
