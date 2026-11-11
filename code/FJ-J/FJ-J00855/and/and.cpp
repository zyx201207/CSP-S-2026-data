#include<bits/stdc++.h>
using namespace std;
int n,m,ans=-1e9,cnt;
long long a[2005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				cnt=a[i] & a[j];
				ans=max(ans,cnt);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans & a[i]; 
		}
		cout<<ans;
		return 0; 
	}
}
