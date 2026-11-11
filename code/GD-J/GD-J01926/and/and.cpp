#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=-200005,c,d;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans=max(a[i]&a[j],ans);
			c=a[i];
			d=a[j];
		}
	}if(m==2){
		cout<<ans;
		return 0;
	}while(m--){
		for(int i=1;i<=n;i++){
			if(i!=c&&i!=d){
				ans=max(ans,ans&a[i]);
				c=ans;
				d=a[i];
			}
		}
	}cout<<ans;
	return 0;
}
