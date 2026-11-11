#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(NULL);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		long long maxn=-10000;
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
		return 0;
	}
	else if(m==n){
		long long sum=a[1];
		for(int i=2;i<=n;i++){
			sum=sum&a[i];
		}
		cout<<sum;
		return 0;
	}
	else if(m==2){
		long long maxn=-19000;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
		return 0;
	}
	else if(m==n-1){
		long long maxn=-10000;
		for(int i=1;i<=n;i++){
			if(i==1){
				long long sum=a[2];
				for(int j=3;j<=n;j++){
					sum=sum&a[j];
				}
				maxn=max(maxn,sum);
			}
			else{
				long long sum=a[1];
				for(int j=2;j<=n;j++){
					if(j==i) continue;
					sum=sum&a[j];
				}
				maxn=max(maxn,sum);
			}
		}
		cout<<maxn;
		return 0;
	}
	sort(a+1,a+n+1);
	cout<<a[n-m+1];
	return 0;
}
