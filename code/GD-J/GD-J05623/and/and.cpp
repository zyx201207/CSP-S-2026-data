#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,mx=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(m==1){
		cout<<mx;
		return 0;
	}
	else if(m==n){
		long long ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	else if(m==2){
		long long ans=0;
		for(long long i=1;i<=n-1;i++){
			for(long long j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}cout<<ans;
		return 0;
	}
	else if(m==n-1){
		long long ans=0;
		for(int i=1;i<=n;i++){
			long long cnt;
			long long ind;
			if(i==1){
				cnt=a[2];
				ind=2;
			}
			else{
				cnt=a[1];
				ind=1;
			}
			for(long long j=ind+1;j<=n;j++){
				if(j==i) continue;
				cnt=cnt&a[j];
			}
			ans=max(ans,cnt);
		}
		cout<<ans;
		return 0;
	}
	else if(m==3){
		long long ans=0;
		for(long long i=1;i<=n-2;i++){
			for(long long j=i+1;j<=n-1;j++){
				for(long long k=j+1;k<=n;k++){
					ans=max(ans,a[i]&a[j]&a[k]);
				}
			}
		}cout<<ans;
		return 0;
	}
	else{
		sort(a+1,a+1+n);
		long long ans=a[n];
		for(int i=n-1;i>=n-m+1;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
