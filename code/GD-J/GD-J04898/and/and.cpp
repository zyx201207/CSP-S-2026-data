#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ma=-1,sum=-1,ans;
int main(){
	freopen("and.in ","r",stdin);
	freopen("and.out ","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1) {
		for(int i=1;i<=n;i++){
			ma=max(ma,a[i]);
     	}
     	cout<<ma;
		return 0;
	}
	else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
     	}
     	cout<<ans;
		return 0;
	}
	else if(m==2) {
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				sum=max((a[i]&a[j]),sum);
			}
		}
		cout<<sum;
		return 0;
	}
	else if(m==(n-1)) {
		cout<<0;return 0;
	}
	else {
		ans=a[n];
		for(int i=n-1;i>=(n-m+1);i--){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 


