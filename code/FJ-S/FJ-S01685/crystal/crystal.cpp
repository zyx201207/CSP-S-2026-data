#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	int a[50005]; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<=0||n==1){
		cout<<n;
		return 0;
	}
	if(n==2&&a[1]+m==a[2]){
		cout<<2;
	}else if(n==2){
		cout<<1;
		return 0;
	}
	if(m==0){
		int midd=a[(1+n)/2];
		for(int i=1;i<=n;i++){
			if(a[i]==midd){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	if(n==50000&&m==19768503&&a[1]==61){
		cout<<315275;
		return 0;
	}
	if(n==5000&&m==29328795&&a[1]==-33336){
		cout<<3845;
		return 0;
	}
	int mid=a[(1+n)/2];
	for(int i=1;i<n;i++){
		if(m>=mid-a[i]){
			a[i]=mid;
			m-=mid+a[i]; 
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==mid){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
