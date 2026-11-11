#include<bits/stdc++.h>
using namespace std;
long long int a[200005];
long long int n,m;
long long int ans;
long long int ans1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);	
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==n){
		ans=(a[1]&a[2]);
		for(int i=3;i<=n;i++){
			ans=(a[i]&ans);
		}
		cout<<ans;
	}
	for(int i=n;i>=1;i--){
		if((a[i]&a[i-1])!=0){
			ans=(a[i]&a[i-1]);
			m-=2;
			ans1=i;
			break;
		}
	}
	for(int i=ans1-2;i>=1;i--){
		if(m==0){
			cout<<ans;
			return 0;
		}
		if((ans&a[i])!=0){
			ans=(ans&a[i]);
			m--;
		}
		ans=(ans&a[i]);
		m--;	
	}

	return 0;
}