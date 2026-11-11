#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],cnt;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld %c",&a[i],&c[i]);
	}
	int l=0,r=n-1;
	while(l<r){
		if(a[l]>a[r]){
			if(c[l]!=c[r]){	
				cnt+=a[r];
			}
			a[l]-=a[r];
			r--;
		}
		if(a[l]<a[r]){
			if(c[l]!=c[r]){	
				cnt+=a[l];
			}
			a[r]-=a[l];
			l++;
		}
		if(a[l]==a[r]){
			if(c[l]!=c[r]){	
				cnt+=a[r];
			}
			l++;
			r--;
		}
	}
	printf("%lld",cnt);
	return 0; 
}
