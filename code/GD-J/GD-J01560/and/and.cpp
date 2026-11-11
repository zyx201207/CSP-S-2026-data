#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2000005],ans,max1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		max1=max(max1,a[i]);
	}
	if(m==1){
		cout<<max1;
		return 0;
	}
	sort(a+1,a+1+n);
	if(m==2){
		for(int i=n;i>=1;i--){
			if(a[i]==a[i-1]){
				cout<<a[i];
				return 0;
			}
		}
	}
	else{
		ans=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			ans&=a[i];
		}
		cout<<ans;
	}
	return 0;
}
