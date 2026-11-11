#include<bits/stdc++.h>

using namespace std;

int n,m;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	vector<int> a(n+1);
	if(m==n){
		int ans;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i==1){
				ans=a[1];
			}else{
				ans=ans&&a[i];
			}
		}
		cout<<ans;
		return 0;
	}
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(m==1){
		cout<<mx;
		return 0;
	}
	if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					ans=max(ans,(int)(a[i]&&a[j]));
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(n-1==m){
		int ans=0;
		for(int i=1;i<=n;i++){
			int t;
			for(int j=1;j<i;j++){
				t=t&&a[j];
			}
			for(int j=i+1;j<=n;j++){
				t=t&&a[j];
			}
			ans=max(ans,t);
		}
		cout<<ans;
		return 0;
	}
	
	
	return 0;
}
