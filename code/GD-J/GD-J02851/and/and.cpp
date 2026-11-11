#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200000],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	if(m==2){
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans;
		return 0;
	}else if(m==n-1){
		for(int i=0;i<n;i++){
			long long  j,t;
			if(i==0){
				t=a[1];
				j=2;
			}else{
				j=1;
				t=a[0];
			}
			for(;j<n;j++){
				if(j!=i){
					t=(t&a[i]);
				}
			}
			ans=max(ans,t);
		}
		cout<<ans;
	}else if(m==n){
		ans=a[0];
		for(int i=1;i<n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}else{
		for(int i=0;i<n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}
	return 0;
}
