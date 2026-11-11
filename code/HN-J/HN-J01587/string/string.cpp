#include<bits/stdc++.h>
using namespace std;
long long n,m,k,y,l,r,a[222222];
char c[222222];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(long long i=1;i<=n;i++) scanf("%lld%s",&a[i],&c[i]);
	l=1,r=n;
	while(l+1<r){
		if(c[l]!=c[r])
			if(a[l]>a[r]) y+=a[r];
			else y+=a[l];
		if(a[l]>a[r]){
			a[l]-=a[r];
			r--;
		}
		else{
			a[r]-=a[l];
			l++;
		}
	}
	k=(a[l]+a[r])/2;
	if(a[l]>k&&c[l]!=c[r]) y+=a[r];
	else if(c[l]!=c[r]) y+=a[l];
	cout<<y;
	return 0;
}
