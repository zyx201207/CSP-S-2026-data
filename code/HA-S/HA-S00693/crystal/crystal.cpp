#include<bits/stdc++.h>
using namespace std;
long long m,n,ave,mx;
bool f=1;
long long a[500100],d[500100];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	
	cin>>a[1]>>a[2];
	d[2]=a[2]-a[1];
	for(int i=3;i<=n;i++){
		cin>>a[i];
		d[i]=a[i]-a[i-1];
		if(d[i]!=d[i-1])f=0;
	}
	
	sort(a+1,a+n+1);

	if(f){
		long long i=1,k=0,sum=0;
	    while(sum<=m&&i<n){
		    k+=d[2];
	        i++;
		    sum+=k;
		    
	    }
	    if(sum>m)i--;
	    
		cout<<i;
		
		
	}else if(n<=5000){ 
	long long sum=0,ans=0,k=0;
	
	    for(int i=1;i<=n;i++){
	    	k=0,sum=0;
	    	for(int j=i;j>=1;j--){
	    		k++;
	    		sum+=a[i]-a[j];
				if(sum<=m)ans=max(ans,k);
				else break;
			}

		}

		cout<<ans;
	
   }else {
    
	long long l=1,r=n;
	while(l<=r){
		long long mid=l+r/2;
		long long sum=0,ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]<=mid){
			long long need=mid-a[i];
			sum+=need;
			ans++;
			}
			if(sum>m){
				r=mid-1;
			}else{
				l=mid+1;
				mx=max(mx,ans);
			}
			
		}
	}
	cout<<mx;
	}
	
	return 0;
} 
