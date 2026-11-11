#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005];
int ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n<=2000){
		if(m==1){
			for(int i=1;i<=n;i++){
				ans=max(ans,a[i]);
			}
			cout<<ans<<endl;
		}
		if(m==2){
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					ans=max(ans,(a[i]&a[j]));
				}
			}
			cout<<ans<<endl;
		}
	}else{
		ans=a[n-m+1];
		for(int i=n-m+2;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans<<endl;
	}
}
