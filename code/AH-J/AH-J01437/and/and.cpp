//先打暴力吧
//freopen("string.in","r",stdin)<-----
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200099];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	ll ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(i!=j)
					ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==(n-1)){
		
		for(int i=1;i<=n;i++){
			if(i!=1)ans=a[1];
			else if(i!=2)ans=a[2];
			for(int j=1;j<=n;j++){
				if(i!=j)
					ans&=a[j];
			}
		}
		cout<<ans;
		return 0;		
	}
	else if(a[1]==0){
		cout<<0;
		return 0;
	}
	else{
		ans=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	
	
	return 0;
}


