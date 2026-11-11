#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[n+5],sum[n+5];//int c[n+5];
    //cin>>a[0];
    
    
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    sum[0]=0;
    //for(int i=1;i<n;i++)c[i-1]=a[i]-a[i-1];
    for(int i=1;i<n;i++)sum[i]=sum[i-1]+a[i]-a[i-1];
    long long l=0,r=0,now=1,ns=0,mns=-100000000;
    while(l<n-1&&r<n-1){
		if(ns+now*(sum[r+1]-sum[r])<=m){
			//cout<<ns<<"+"<<c[r]*now<<"="<<(ns+now*c[r]<=m)<<endl;
			ns=ns+now*(sum[r+1]-sum[r]);
			now++;
			r++;
			
		}
		else {
			//cout<<c[r]<<endl;
			ns-=(sum[r]-sum[l]);
			l++;
			now--;
			
		}
		
		mns=max(mns,r-l+1);
	}
	cout<<mns;
    return 0;
}

