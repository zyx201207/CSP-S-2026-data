#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m==1){
		int ans=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	else if(m==2){
		int ans=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				ans=max(ans,(a[i] & a[j]));
			}
		}
		cout<<ans;
		return 0;
	}
	else if(m==n){
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int ans=a[0];
		for(int i=1;i<n;i++){
			ans=(ans & a[i]);
		}
		cout<<ans;
		return 0;
	}
	else if(m==n-1){
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=0;i<n;i++){
			if(i==0){
				int cnt=a[1];
				for(int j=2;j<n;j++){
					if(i!=j){
						cnt=(cnt & a[j]);
					}
				}
				ans=max(ans,cnt);
			}
			else{
				int cnt=a[0];
				for(int j=1;j<n;j++){
					if(i!=j){
						cnt=(cnt & a[j]);
					}
				}
				ans=max(ans,cnt);
			}
		}
		cout<<ans;
	}
}
