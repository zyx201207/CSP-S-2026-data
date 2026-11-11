#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
long long ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
    	cin>>a[i];
    }
    if(n==m){
    	ans=a[0];
    	for(int i=1;i<n;i++){
    		ans&=a[i];
    	}
    	cout<<ans;
    	return 0;
    }
    if(m==1){
    	sort(a,a+n);
    	cout<<a[n-1];
    	return 0;
    }
    if(m==2){
    	for(int i=0;i<n;i++){
    		for(int j=i+1;j<n;j++){
    			ans=max(ans,a[i]&a[j]);
    		}
    	}
    	cout<<ans;
    	return 0;
    }
    if(m=n-1){
    	ans=a[0];
    	for(int i=1;i<n-1;i++){
    		ans&=a[i];
    	}
    	long long cnt=a[1];
    	for(int i=2;i<n;i++){
    		cnt&=a[i];
    	}
    	ans=max(ans,cnt);
    	cout<<ans;
    	return 0;
    }
    sort(a,a+n);
    cout<<a[n-1];
	return 0;
}
