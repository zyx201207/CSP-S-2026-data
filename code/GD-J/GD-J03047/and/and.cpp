#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],m,ans=-1,f;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	if(m==1){
		for(int i=1;i<=n;i++) ans=max(a[i],ans);
	}
	else{
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				f=a[i]&a[j];
				ans=max(ans,f);
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
