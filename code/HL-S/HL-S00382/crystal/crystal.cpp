#include<bits/stdc++.h>

using namespace std;
	long long a[500005],n,m,ma=0;
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
    for(long long i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n-1;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	for(long long i=n;i>=1;i--){
		long long sum=0;
		for(long long j=i;j>=1;j--){
			int c=a[i]-a[j];
			if(sum+c<=m){
				sum++;
			}
		}
		ma=max(ma,sum);
		sum=0;
	}
	cout<<ma;
	return 0;
}
