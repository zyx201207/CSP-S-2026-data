#include<bits/stdc++.h>
using namespace std;
long long n,a[100005],ans;
char c[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		cin>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		int k=min(a[l],a[r]);
		if(c[l]!=c[r])ans+=k;
		a[l]-=k,a[r]-=k;
		if(a[l]==0)l++;
		if(a[r]==0)r--;
	}
	printf("%lld",ans);
	return 0;
}
