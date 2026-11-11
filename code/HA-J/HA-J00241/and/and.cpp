#include<bits/stdc++.h>
using namespace std;
int n,m,ans,v[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	if(m==1){
		for(int i=2;i<=n;i++)ans=max(ans,v[i]);
		cout<<ans;
		return 0;
	}
	else if(n==m){
		ans=v[1];
		for(int i=2;i<=n;i++){
			ans&=v[i];
		}
		cout<<ans;
		return 0;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j)ans=max(ans,v[i]&v[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	else if(n-m==1){
		for(int i=1;i<=n;i++){
			int sum=v[1];
			if(i==1)sum=v[2];
			for(int j=1;j<=n;j++){
				if(j!=i)sum&=v[j];
			}
			ans=max(sum,ans);
		}
		cout<<ans;
		return 0;
	}
	else cout<<0;
	return 0;
}
