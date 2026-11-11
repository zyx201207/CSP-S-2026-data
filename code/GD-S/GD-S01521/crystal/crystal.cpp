#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
long long a[500005]={0},b[500005]={0};
bool flag=true;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>=3 && a[i]-a[i-1]!=a[i-1]-a[i-2]) flag=false;
    }
    sort(a+1,a+n+1);
    if(flag){
    	int k=(n+1)/2,t=1;
    	while(m>=0){
    	    if(m>=a[k]-a[k-t] && k-t>=1){
    	        ans++;
    	        m-=a[k]-a[k-t];
    	    }
    	    if(m>=a[k+t]-a[k] && k+t<=n){
    	        ans++;
    	        m-=a[k+t]-a[k];
    	    }
    	    else break;
    	    t++;
    	}
    	ans++;
	}
	else{
		int sum,t;
		for(int i=1;i<=a[n];i++){
			sum=0,t=m;
			for(int j=1;j<=n;j++){
				b[j]=i-a[j];
			}
			sort(b+1,b+n+1);
			for(int j=1;j<=n;j++){
				if(b[j]>=0){
					if(t>=b[j]){
						t-=b[j];
						sum++;
					}
				}
			}
			ans=max(sum,ans);
		}
	}
//	for(int i=1;i<=n;i++) cout<<b[i]<<' ';
    cout<<ans;
    return 0;
}

