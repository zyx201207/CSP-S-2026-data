#include<bits/stdc++.h>
using namespace std;
char c[200009];
int a[200009];
int n,l,r;
long long ans=0;
int x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d %c",&a[i],&c[i]);
	}
	l=1,r=n;
	while(l < r){
		if(c[l]!=c[r]){
			ans+=min(a[l],a[r]);
//			cout << l << " " << r << endl;
		}
		x=min(a[l],a[r]);
		a[l]-=x;
		a[r]-=x;
		if(a[l]<=0){
			l++;
		}
		if(a[r]<=0){
			r--;
		}
	}
	printf("%lld",ans);
	return 0;
}
