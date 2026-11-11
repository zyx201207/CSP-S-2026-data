#include<bits/stdc++.h>
using namespace std;
int n,cnt=1,ans;
long long m,a[500005],x;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<=5000){
	    for(int j=0;j<n-1;j++){
	    	int cnt=1;
	    	x=m;
	        for(int i=n-j;i>1;i--){
		        if(a[n-j]-a[i-1]<=x){
			        x-=a[n-j]-a[i-1];
			        cnt++;
		        }
	        }
	        ans=max(ans,cnt);
	    }
	}
	else{
		cnt=1;
		for(int i=n;i>1;i--){
		    if(a[n]-a[i-1]<=m){
			    m-=a[n]-a[i-1];
			    ans++;
		    }
	    }
	}
	cout<<ans;
	return 0;
}
