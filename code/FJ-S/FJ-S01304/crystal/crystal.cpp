#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long a[N+1];
long long f[N+1];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m,m1;
	scanf("%d",&n);
	scanf("%lld",&m1);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	f[0]=0;
	for(int i=1;i<n;i++){
		f[i]=a[i]-a[i-1];
	}
	int maxx=0;
	for(int k1=1;k1<n;k1++){
		int k2=k1-1;
		int k=k1;
		if(n-k+1<maxx){
			break;
		}
    	int ans=1;
    	m=m1;
	    while(m>0&&k<n){
		    if(f[k]>0){
			    m=m-((k-k2)*f[k]);
			    if(m>=0){
				    ans++;
		    	}
			    f[k]=0;
    			if(m==0){
	    			k=k+1;
		    		while(k<n&&f[k]==0){
			    		k++;
    				    	ans++;
	    			}
		    		break;
			    }
		    }
		    k++;
    	}
	    //cout<<ans;
	    if(ans>=maxx) maxx=ans;
    }
    printf("%d",maxx);
	return 0;
}
