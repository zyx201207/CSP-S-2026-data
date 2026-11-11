#include <bits/stdc++.h>
using namespace std;
int a[200005];
int n,m,ans=0;
int awy(int b,int c){
	return b&c;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
	}
	else if(m==2){
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				if(ans<awy(a[i],a[j])){
					ans=awy(a[i],a[j]);
				}
			}
		}
		cout<<ans;
		return 0;
	}
	else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=awy(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	else if(m==n-1){
		ans=a[2];
		for(int i=3;i<=n;i++){
			ans=awy(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	else{
		ans=a[n];
		for(int i=n-1;i>n-m;i--){
			ans=awy(ans,a[i]);
		}
		cout<<ans;
	}
	return 0;
}

