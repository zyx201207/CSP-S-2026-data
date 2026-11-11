//GZ-J00575 ´úÒã³Ð 
#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
long long n,a[maxn],num=0,ans=0,lon=0;
char c[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		scanf("%lld %c",&a[i],&c[i]);
		lon+=a[i];
	}
	num=lon>>1;
	long long l=1,r=n;
	for(long long i=1;i<num;i++){
		long long ne,aa=0;
		if(c[l]==c[r]&&a[l]!=0&&a[r]!=0){
			if(a[l]>a[r]){
				ne=a[r];
				a[l]-=ne;
				a[r]-=ne;
				r--;
			}
			if(a[l]<a[r]){
				ne=a[l];
				a[l]-=ne;
				a[r]-=ne;
				l++;
			}
			if(a[l]==a[r]){
				ne=a[l];
				a[l]-=ne;
				a[r]-=ne;
				l++;
				r--;
			}	
		}
		if(c[l]!=c[r]&&a[l]!=0&&a[r]!=0){
			if(a[l]>a[r]){
				ne=a[r];
				a[l]-=ne;
				a[r]-=ne;
				r--;
			}
			if(a[l]<a[r]){
				ne=a[l];
				a[l]-=ne;
				a[r]-=ne;
				l++;
			}
			if(a[l]==a[r]){
				ne=a[l];
				a[l]-=ne;
				a[r]-=ne;
				l++;
				r--;
			}
			ans+=ne;
		}
		num=num-ne; 
	}
	printf("%lld ",ans);
	return 0;
}

