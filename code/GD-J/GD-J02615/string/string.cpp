#include<bits/stdc++.h>
using namespace std;
long long n,ans,a[200000+5];
char c[200000+5];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld" ,&a[i]);
		c[i]=getchar();
		c[i]=getchar();
	}
	for(int l=1,r=n;l<r;){
		if(c[l]==c[r]){
			if(a[l]>a[r]) 
				a[l]-=a[r],r--;
			else if(a[l]<a[r])
				a[r]-=a[l],l++;
			else if(a[l]==a[r])
				l++,r--;
		}
		else{
			if(a[l]>a[r]) 
				a[l]-=a[r],ans+=a[r],r--;
			else if(a[l]<a[r])
				a[r]-=a[l],ans+=a[l],l++;
			else if(a[l]==a[r])
				ans+=a[r],l++,r--;
		}
	}
	printf("%lld",ans);
	return 0;
} 
