#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int N=2e5+10;
int a[N];
int n,m;

signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdin);
	cin>>n>>m;
	int f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1)f=0;
	}
	if(m==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans<<endl;
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans<<endl;
		return 0;
	}
	if(m==2){
		int ans=0;
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	if(m==n-1){
		int sum=a[2];
		for(int i=3;i<=n;i++){
			sum=sum&a[i];
		}
		int ans=sum;
		for(int i=2;i<=n;i++){
			int x=a[1];
			for(int j=2;j<i;j++){
				x=x&a[j];
			}
			for(int j=i+1;j<=n;j++){
				x=x&a[j];
			}
			ans=max(ans,x);
		}
		cout<<ans<<endl;
		return 0;
	}else{
		int ans=0;
		for(int i=1;i+m-1<=n;i++){
			int x=a[i];
			for(int j=i+1;j<=i+m-1;j++){
				x=x&a[i];
			}
			ans=max(ans,x);
		}
		cout<<ans<<endl;
	}
	if(f){
		sort(a+1,a+n+1);
		int ans=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			ans=ans&a[i];
		}
		cout<<ans<<endl;
		return 0;
	}
	return 0;
}
