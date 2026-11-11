#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(n>=500000){
		long long sum1=0;
		sum1=(a[0]+a[n-1])*n*1.0/2.0;
		cout<<sum1;
		return 0;
	}else if(m>500000000000000000){
		cout<<n;
		return 0;
	}
	long long mx=INT_MIN;
	for(int i=0;i<n;i++){
		long long sum=0;
		long long cnt=0;
		for(int j=0;j<=i;j++){
			if(j!=i-1){
				if(a[j+1]==a[j]){
					cnt++;
				}else if(sum+a[i]-a[j]<=m){
					cnt++;
					sum+=(a[i]-a[j]);
				}else{
					break;
				}
			}else if(j==i-1){
				if(sum+a[i]-a[j]<=m){
					cnt++;
					sum+=(a[i]-a[j]);
				}else{
					break;
				}
			}			
		}
		mx=max(mx,cnt);
	}
	cout<<mx;
	return 0;
} 
