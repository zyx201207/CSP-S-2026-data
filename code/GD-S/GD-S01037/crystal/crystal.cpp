#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=1,num=1;
long long sum[500005];
bool check(){
	long long d=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(!(a[i]-a[i-1]==d)){
			return false;
		}
	}
	return true;
}
int main(){
	//freopen("crystal.in","r",stdin);////////
	//freopen("crystal.out","w",stdout);//////
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	if(check()){
		long long d=a[2]-a[1];
		long long num=m/d;
		for(int i=1;i<n;i++){
			if(num>=i){
				ans++;
				num-=i;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int k=1;k<n;k++){
		for(int i=1;i+k<=n;i++){
			int j=i+k-1;
			if(a[j]*k-(sum[j]-sum[i-1])){
				ans=k-1;
				break;
			} 
		}
	}
	cout<<ans;
	return 0;
	
} 
