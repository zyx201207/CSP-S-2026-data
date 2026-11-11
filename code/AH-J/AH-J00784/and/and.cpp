#include<bits/stdc++.h>
using namespace std;
int a[200004];
int maxn=-1,ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n, m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
	}
	else if(m==2){
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<n-1){
				if(i!=j){
					maxn=max(maxn,a[i]|a[j]);
				}
			}
		}
	}
	else if(m==n){
		for(int i=1;i<=n;i++){
			if(i==1){
				ans=a[i];
		}
		else ans=ans|a[i];
		}
		cout<<ans;
	}
	else if(m==n-1){
		for(int i=1;i<=n;i++){
			ans=0;
			for(int j=1;j<=n;j++){
				if(j!=i){
					if(j==1){
						ans=a[j];
					}
					else ans=ans|a[j];
				}
			}
			maxn=max(maxn,ans);
		}
		cout<<maxn;
	}
	return 0;
}

