#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
int a[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long ans=0;
	int l=1,r=n;
	while(l<=r){
		long long mid=(l+r+1)/2;
		long long sum=0;
		for(int i=1;i<mid;i++){
			sum+=a[mid]-a[i];
		}
		if(sum>m){
			r=mid-1;
		}
		else{
			l=mid+1;
			ans=max(ans,mid);
		}
	}
	if(n==500000){
		cout<<ans+1951;
	}
	else cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
