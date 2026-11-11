#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500020];
int ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		int sum=m;
		for(int j=i-1;j>=0;j--){
			sum-=(a[i]-a[j]);
			if(sum<=0){
				ans=max(ans,i-j+1);
				break;
			}
		}
	}
	printf("%d",ans);
} 
