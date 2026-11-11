//GZ-J00424 张云景 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],ans;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
		getchar();
		scanf("%c",&c[i]);
		getchar();
	}
	long long l=0,r=n-1;
	while(1){
		if(l>=r)break;
		if(c[l]!=c[r])ans+=min(a[l],a[r]);
		if(a[l]>a[r])a[l]-=a[r],r--;
		else if(a[l]<a[r])a[r]-=a[l],l++;
		else l++,r--;
	}
	printf("%lld",ans);
	return 0;
}
