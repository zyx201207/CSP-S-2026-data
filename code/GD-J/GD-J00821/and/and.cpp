#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		long long max_=0;
		for(int i=1;i<=n;i++){
			max_=max(max_,a[i]);
		}
		cout<<max_;
	}else if(m==2){
		long long max_=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				max_=max(max_,(a[i]&a[j]));
			}
		}
		cout<<max_;
	}else if(m==n){
		long long ans=(a[1]&a[2]);
		for(int i=3;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
	}else if(m==n-1){
		long long ans1=(a[1]&a[2]);
		long long ans2=(a[2]&a[3]);
		for(int i=3;i<=n;i++){
			if(i==3){
				ans1=(ans1&a[i]);
			}else if(i==n){
				ans2=(ans2&a[i]);
			}else{
				ans1=(ans1&a[i]);
				ans2=(ans2&a[i]);
			}
		}
		cout<<max(ans1,ans2);
	}else{
		
	}
	return 0;
}
