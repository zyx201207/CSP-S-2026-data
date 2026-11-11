#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;	cin>>n>>m;
	if(n==m+1){
		long long max3=0;
		for(int i=1;i<=n;i++){
			long long max2=INT_MAX;
			for(int j=1;j<=n;j++){
				if(j==i){
					continue;
				}else{
					max2=max2&a[j];
				}
			}
			max3=max(max3,max2);
		}
		cout<<max3;
	}
	if(m==2){
		long long max4;
		for(int i=1;i<=n;i++){
			long long max5=a[i];
			for(int j=i+1;j<=n;j++){
				if(j==i){
					break;
				}
				max5=max5&a[j];
			}
			max4=max(max4,max5);
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long max1=a[n];
	for(int i=n-1;i>=n-m+1;i--){
		max1=max1&a[i];
	}
	cout<<max1;
	return 0;
}
