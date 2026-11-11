#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m==n){
		int ans;
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			if(i==1){
				ans=k;
				continue;
			}
			ans=ans&k;
		}
		cout<<ans;
	}else if(m==2){
		int ans=-1;
		int k[n+10]={};
		for(int i=1;i<=n;i++){
			cin>>k[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,k[i]&k[j]);
			}
		}
		cout<<ans;
	}else if(m==1){
		int ans=-1;
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			ans=max(ans,k);
		}
		cout<<ans;
	}else{
		int k[n+10]={};
		for(int i=1;i<=n;i++){
			cin>>k[i];
		}
		sort(k,k+n+1);
		cout<<k[n-m+1];
	}
	return 0;
}
