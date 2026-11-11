#include<iostream>
#include<cstdio>
using namespace std;
int n;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i],&c[i]);
	}
	int l=1,r=n;
	long long ans=0;
	while(r>l){
		int tmp=min(a[l],a[r]);
		if(c[l]!=c[r]){
			ans+=tmp;
		}
		a[l]-=tmp;
		a[r]-=tmp;
		if(a[l]==0){
			l++;
		}
		if(a[r]==0){
			r--;
		}
	}
	printf("%lld",ans);
	return 0;
}
