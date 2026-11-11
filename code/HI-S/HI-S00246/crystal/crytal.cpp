#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
long long n,m,a[maxn],aa[maxn];
long long ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	aa[1]=a[1];aa[0]=0;sort(a+1,a+n+1); 
    for(int i=2;i<=n;i++) aa[i]=aa[i-1]+a[i];
	for(int i=2;i<=n;i++){
		if(aa[i-1]+m>=a[i]*(i-1)) ans=i;
	}
	cout<<ans;
	return 0;
}

