#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==1){
		cout<<a[n];
	}
	else if(m==n){
		int sum=a[1];
		for(int i=2;i<=n;i++){
			sum=sum&a[i];
		}
		cout<<sum;
	}
	else if(m==2){
		int maxx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
	}
	else if(m==n-1){
		int sum=a[1],num=a[2];
		for(int i=2;i<n;i++){
			sum=sum&a[i];
		}
		for(int i=3;i<=n;i++){
			num=num&a[i];
		}
		cout<<max(num,sum);
	}
	else{
		int size=n,ans=a[n];
		for(int i=m-1;i>=1;i--){
			size--;
			ans&=a[size];	
		}
		cout<<ans;
	}
	return 0;
} 
