#include<bits/stdc++.h>
using namespace std;
const int N=200005;
long long m,n,ans;
long long a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans=max(ans,a[i]);
		
	}
	if(m==1){
		printf("%lld",ans);
		return 0;
	}
	if(m==2){
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				ans=max(ans,a[i]&a[j]);
			}
		}
		printf("%lld",ans);
		return 0;
	}
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(i==j||i==k||j==k)continue;
				ans=max(ans,a[i]&a[j]&a[k]);
			}
		}
	}
	printf("%lld",ans);
	return 0; 
} 
