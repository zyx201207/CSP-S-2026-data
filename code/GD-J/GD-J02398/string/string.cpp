#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=2e5+10;
int n;
ll a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%s",&a[i],&c[i]);
    }
    int l=1,r=n;
    ll ans=0;
    while(l<=r){
    	if(a[l]>a[r]){
    		if(c[l]!=c[r])ans+=a[r];
    		a[l]-=a[r];
    		r--;
		}else if(a[l]<a[r]){
			if(c[l]!=c[r])ans+=a[l];
			a[r]-=a[l];
			l++;
		}
		if(a[l]==a[r]){
			if(c[l]!=c[r])ans+=a[l];
			l++;r--;
		}
	}
	printf("%lld",ans);
	return 0;
}
/*
3
2 a
2 b
1 c

2 
2 a
3 a
 
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/

