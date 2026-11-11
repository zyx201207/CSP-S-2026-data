#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005]; 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool f1=0,f2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) f1=1;
	}
	for(int i=2;i<n;i++){
		if(a[i]-a[i-1]!=a[i+1]-a[i]) f2=1;
	}
	sort(a+1,a+n+1);
	if(!f1){
		int sum=(n-1)*n/2;
		if(sum<=m){
			cout<<n<<endl;
			return 0;
		}
		int sum1=0;
		for(int i=1;i<=n;i++){
			if(sum1>m){
				cout<<i-1<<endl;
				break;
			}
			else if(sum1==m){
				cout<<i<<endl;
				break;
			}
			sum1+=i;
		}
	}
	else if(!f2){
		int sum1=0;
		int d=a[2]-a[1];
		for(int i=1;i<=n;i++){
			if(sum1>m){
				cout<<i-1<<endl;
				break;
			}
			else if(sum1==m){
				cout<<i<<endl;
				break;
			}
			sum1+=i*d;
		}
	}
	else {
		int sum1=0;
		for(int i=1;i<=n;i++){
			sum1+=(a[i]-a[1]);
		}
		if(sum1<=m){
			cout<<n<<endl;
			return 0;
		}
		int ans=0;
		int sum=0;
		for(int i=1;i<=n;i++){
			sum=0;
			for(int j=i-1;j>=1;j--){
				sum+=(a[i]-a[j]);
				if(sum>m){
					//cout<<i<<" "<<j<<" "<<sum<<" "<<i-j<<endl;
					ans=max(ans,i-j);
					break;
				}
				if(sum==m){
					ans=max(ans,i-j+1);
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
