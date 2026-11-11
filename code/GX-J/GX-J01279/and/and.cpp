#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
int main(){
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ans=max(ans,a[i]);
	    }
	}else if(m==n){
		cin>>a[1];
		for(int i=2;i<=n;i++){
			cin>>a[i];
			a[i]=a[i]&a[i-1];
		}
		ans=a[n];
    }else if(m==2){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		ans=max(a[n]&a[n-1],a[n-2]&a[n-1]);
    }else if(n-1==m){
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+1+n);
		ans=a[n];
		for(int i=2;i<=m;i++){
			ans=ans&a[n-i+1];
		}
		ans=a[2];
	}else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		ans=a[n-m+1];
	}
	cout<<ans;
    return 0;
}
