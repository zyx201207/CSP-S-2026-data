#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,k;cin>>n>>k;
	long long a[200005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==1){
		sort(a+1,a+1+n);
		cout<<a[n];
	}else if(k==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if((a[i]&a[j])>ans)ans=(a[i]&a[j]);
			}
		}
		cout<<ans;
	}else if(k==3){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int v=j+1;v<=n;v++){
					if((a[i]&a[j]&a[v])>ans)ans=(a[i]&a[j]&a[v]);
				}
			}
		}
		cout<<ans;
	}else{
		sort(a+1,a+1+n);
		int ans=a[n];
		for(int i=2;i<=k;i++){
			ans=(ans&a[n-i+1]);
		}
		cout<<ans;
	}
	return 0;
} 
