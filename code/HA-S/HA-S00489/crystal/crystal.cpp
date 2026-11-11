#include<bits/stdc++.h>
using namespace std;
long long n,m,sum;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool A=1,B=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)A=0;
	}
	if(A){
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=i;
			if(sum>m){
				cout<<i;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	int c;
	c=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=c)B=0;
	}
	if(B){
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=i*c;
			if(sum>m){
				cout<<i;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=n;i>=1;i--){
		int sum=0;
		for(int j=i;j>=1;j--){
			sum+=(a[i]-a[j]);
			if(sum==m){
				ans=max(ans,i-j+1);
				break;
			}
			if(sum>m){
				ans=max(ans,i-j);
				break;
			}
		}
		if(n-i+1+ans>=n)break;
	}
	cout<<ans;
	return 0;
}


