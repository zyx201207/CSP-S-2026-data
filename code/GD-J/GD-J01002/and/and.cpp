#include<iostream>
#include<algorithm>
using namespace std;
long long a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>a[1];
	long long ans=a[1],ma=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		ans=a[i]&ans;
		ma=max(ma,a[i]);
	}
	sort(a+1,a+n+1);
	
	if(m==n) cout<<ans;
	else if(m==1) cout<<ma;
	else if(m==2&&n<=2000){
		long long ans1=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans1=max(a[i]&a[j],ans1);
			}
		}
		cout<<ans1;
	}
	else{
		long long ans2=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			ans2=ans2&a[i];
		}
		cout<<ans2;
	}
	return 0;
} 
