//GZ-S00321  李琥博  遵义市南白中学 
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500005];
ll mx=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=n;i>=1;i--){
		for(int j=n;j>1;j--){
			if(a[j]>a[j-1]) swap(a[j],a[j-1]);
		}
	}
	for(int i=1;i<n;i++){
		ll ans=1,k=m;
		for(int j=i+1;j<=n;j++){
			if(k-a[i]+a[j]>=0&&k>0){
				k=k-a[i]+a[j];
				ans++;
			}else{
				break;
			}
		}
		mx=max(ans,mx);
	}
	printf("%d",mx);
	fclose(stdin);
	fclose(stdout);
}

