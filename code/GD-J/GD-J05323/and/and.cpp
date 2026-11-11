#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	if(m==n){
		long long sum;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i==1){
				sum=a[i];
				continue;
			}
			sum=(sum&a[i]);
		}
		cout<<sum;
		return 0;
	}	
	else if(m==1){
		long long sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sum=max(int(sum),a[i]);
		}
		cout<<sum;
		return 0;
	}
	else if(m==2){
		long long mx=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			long long sum=a[i],sum1=a[i];
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				mx=max(int(mx),(a[i]&a[j]));
			}
			
		}
		cout<<mx;
		return 0;
	}
	else{
		long long sum;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		sum=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			sum=sum&a[i];
		}
		cout<<sum;
		return 0;
	}
} 
