#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],l=1,r,ans;
char c,s[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	scanf("%lld",&n),r=n;
	for(long long i=1;i<=n;i++)
		scanf("%d%c%c",&a[i],&c,&s[i]);
	while(l!=r){
			if(s[l]!=s[r]){
				if(a[l]<a[r])
					a[r]-=a[l],ans+=a[l],l++;
				else
					a[l]-=a[r],ans+=a[r],r--;
			}
			else{
				if(a[l]<a[r])
					a[r]-=a[l],l++;
				else
					a[l]-=a[r],r--;
			}
	}
	printf("%lld",ans);
    return 0;
}
