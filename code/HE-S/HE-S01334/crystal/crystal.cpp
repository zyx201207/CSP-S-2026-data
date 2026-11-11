#include<bits/stdc++.h>
using namespace std;
long long a[5*100000+10];
long long f[5*100000+10];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long ans=1;
    for(long long i=2;i<=n;i++){
    	long long t=0;
    	for(long long j=i-1;j>=1;j--){
    		t+=(a[i]-a[j]);
    		if(t>m){
    			ans=max(ans,i-j);
    			break;
			}
		}
	}
	cout<<ans;
	return 0;
}
