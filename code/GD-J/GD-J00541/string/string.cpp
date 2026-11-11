#include <bits/stdc++.h>
using namespace std;
int n,a[201000];
char s[201000][2];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%s",&a[i],s[i]+1);
	int l=1,r=n;
	long long ans=0;
	while(l<r){
		int add=min(a[l],a[r]);
		if(s[l][1]!=s[r][1])ans+=add;
		a[l]-=add,a[r]-=add;
		if(a[l]==0)l++;
		if(a[r]==0)r--;
	}
	printf("%lld\n",ans);
}
