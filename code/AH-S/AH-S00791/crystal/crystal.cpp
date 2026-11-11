#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005],b[500005];
long long ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=5000){
        for(int i=1;i<n;i++){
		    b[i]=a[i+1]-a[i];
	    }
	    long long cnt=0,ans1=1;
	    for(int i=1;i<n;i++){
		    for(int j=i+1;j<=n;j++){
		    	cnt=cnt+b[j-1]*(j-i);
			    if(m>=cnt){
				    ans1++;
			    }else{
				    break;
			    }
		    }
		    cnt=0;
		    ans=max(ans,ans1);
		    ans1=1;
	    }
	    cout<<ans;
	    return 0;
	}
	bool ok=1;
	long long x=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(x!=a[i]-a[i-1]){
			ok=0;
		}
	}
	if(ok){
	    int l=1;
	    while(m>0){
		    if(m>=l*x){
			    ans++;
		    }
		    m=m-l*x;
		    l++;
	    }
	    cout<<ans;
	    return 0;
    }
	return 0;
} 
