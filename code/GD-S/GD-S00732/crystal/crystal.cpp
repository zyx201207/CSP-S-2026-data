#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],f[N],ans=0;
long long fin(long long en){
	long long l=1,r=en-1;
	while(l<r){
		long long mid=(l+r)/2,num=a[en]*(en-mid)-(f[en-1]-f[mid-1]);
		if(num>m) l=mid+1;
		else r=mid;
	}
	return en-r+1;
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) f[i]=f[i-1]+a[i];
	for(int i=1;i<=n;i++){
		ans=max(ans,fin(i));
	}
	cout<<ans;
	return 0;
}

