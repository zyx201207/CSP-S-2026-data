#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans[200005],k=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2){
		for(int i=1;i<=n;i++){
		    for(int j=i+1;j<=n;j++){
			    ans[k]=a[i]&a[j];
			    k++;
		    }
	    }
	    sort(ans+1,ans+1+k);
	    cout<<ans[k];
	}
	else if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
	}
	else if(m==n){
		ans[1]=a[1];
		for(int i=2;i<=n;i++){
			ans[i]=ans[i-1]&a[i];
		}
		cout<<ans[n];
	}
	else if(m==n-1){
		ans[1]=a[2];
		for(int i=2;i<=n;i++){
			ans[1]=ans[1]&a[i];
		}
		for(int i=2;i<=n;i++){
			ans[i]=a[1];
			for(int j=1;j<=n;j++){
				if(a[j]!=a[i]){
					ans[i]=ans[i]&a[j];
				}
			}
		}
		sort(ans+1,ans+1+n);
		cout<<ans[n];
	}
    return 0;
}
