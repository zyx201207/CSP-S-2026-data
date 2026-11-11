#include <bits/stdc++.h>
using namespace std;
int a[500005],ans[500005],sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	int len=0;
	for(int i=a[0];i<=a[n-1];++i){
		if(i>=a[len+1])++len;
		for(int j=len;j>=0;--j){
			if(ans[j]+(i-a[j])<=m){
				ans[j]+=(i-a[j]),++sum[j];
			}else break;
		}
	}
	sort(sum,sum+n,greater<int>());
	printf("%d\n",sum[0]);
	return 0;
}
