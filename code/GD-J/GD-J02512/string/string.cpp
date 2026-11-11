#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i],&c[i]);
	} 
	int ta=1,tb=n;
	LL ans=0;
	while(ta<tb){
		if(c[ta]!=c[tb]){
			ans+=min(a[ta],a[tb]);
		}
		if(a[ta]>a[tb]){
			a[ta]-=a[tb];
			a[tb]=0;
			tb--;
		}else if(a[ta]<a[tb]){
			a[tb]-=a[ta];
			a[ta]=0;
			ta++;
		}else{
			a[ta]=a[tb]=0;
			ta++;tb--;
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}//AC
