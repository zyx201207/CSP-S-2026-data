#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1,greater<int>());
		cout<<a[1];
	}else if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<n;j++){
				ans=max(ans,a[i]&a[i-1]);
			}
		}
		cout<<ans;
	}else if(m==n){
		int sum=a[1];
		for(int i=2;i<=n;i++){
			sum&=a[i];
		}
		cout<<sum;
	}else if(m==n-1){
		int sum1=a[1];
		for(int i=1;i<n;i++){
			sum1&=a[i];
		}
		int sum2=a[2];
		for(int i=2;i<=n;i++){
			sum2&=a[i];
		}
		cout<<max(sum1,sum2);
	}
	return 0;
} 
