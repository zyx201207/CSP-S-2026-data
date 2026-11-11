#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[200005];
int ans,ma=-1;
bool f=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1){
			f=1;
		}
	}
	if(m==n){
		ans=pow(2,30)-1;
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				ma=max(ma,a[i]&a[j]);
			}
		}cout<<ma;
		return 0;
	}
	if(m==n-1){
		for(int i=1;i<=n;i++){
			ans=pow(2,30)-1;
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				ans&=a[j];
			}
			ma=max(ma,ans);
		}
		cout<<ma;
		return 0;
	}
	if(f==0){
		if(m<n/2){
			cout<<0;
			return 0;
		}
		ans=pow(2,30)-1;
		for(int i=n,j=1;j<=m;i--,j++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	ans=a[n];
	for(int i=n-1,j=1;j<m;i--,j++){
		ans&=a[i];
	}cout<<ans;
	return 0;
}

