#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[200006];
char p[200006];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>p[i];
		cnt+=a[i];
	}
	long long mid=(cnt+1)/2;
	long long z=1,bi=1;
	while(mid>0&&a[z]<=mid){
		mid-=a[z];
		z++;
	}
	long long zl=z,midl=a[z]-mid;
	mid-=1;
	long long ans=0;
		while(z>=1&&zl<=n){
		if(mid<=1){
			z--;
			mid=a[z];
			bi=0;
		}
		if(midl<=0){
			midl=a[zl+1];
			zl++;
		}
		long long kl=min(mid,midl);
		if(p[z]!=p[zl]){
			ans+=kl;
		}
		mid-=kl,midl-=kl;
	}
	if(bi==1){
		cout<<0;
		return 0;
	}
	if(mid>0||midl>0)ans+=mid+midl;
	cout<<ans;
	return 0;
}
