#include<bits/stdc++.h>
using namespace std;
long long a[5000010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long maxn=0;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		long long qaz=m;
	    for(long long j=i-1;j>=1;j--){
	    	if(a[i]-a[j]<m){
	    		m=m-a[i]+a[j];
			}else{
				maxn=max(i-j+1,maxn);
				break;
			}if(j==1){
				maxn=max(maxn,i);
			}
		}
		m=qaz;
	}
	cout<<maxn<<"\n";
	return 0;
}
