#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+50;
int n,a[N];
ll s=0;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d %c",&a[i],&c[i]);
	int l=1,r=n;
	while(l!=r){
		if(a[l]>=a[r]){
			a[l]-=a[r];
			if(c[l]!=c[r]) s+=a[r];
			r--;
		}
		else {
			a[r]-=a[l];
			if(c[l]!=c[r]) s+=a[l];
			l++;
		}
	}
	printf("%lld",s);
	return 0;
}