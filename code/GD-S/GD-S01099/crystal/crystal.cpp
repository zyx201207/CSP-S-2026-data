#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500005],c[1005],m,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(a[n]<=100&&n>5000){
		for(int i=1;i<=n;i++){
			c[a[i]]=max(c[a[i]],(long long)i);
		}
		for(int i=1;i<=a[n];i++){
			long long sum=0,mm=m;
			for(int j=c[i];j>=1;j--){
				if(i-a[j]<=mm){
					mm-=(i-a[j]);
					sum++;
				}
			}
			ans=max(ans,sum);
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		long long sum=1;
		long long mm=m;
		for(int j=i-1;j>=1;j--){
			if(a[i]-a[j]<=mm){
				mm-=(a[i]-a[j]);
				sum++;
			}
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
} 
//60
