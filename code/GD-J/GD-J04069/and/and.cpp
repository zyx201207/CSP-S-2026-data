#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long dp[200005];
long long a[200005];
long long b[200005],s[200005];
long long sum=1;
long long sum2=1;
long long minn=LLONG_MAX;
long long tp;
int main(){
	long long ji=0;
	long long ou=0; 
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
    	cin>>a[i];
    	if(a[i]%2==1){
    		ji++;
    		b[sum]=a[i];
    	//	cout<<sum<<" "<<b[sum]<<endl;
    		sum++;
		}
		else{
			s[sum2]=a[i];
			sum2++;
			minn=min(minn,a[i]);
			ou++;
		}
	}
	sort(a+1,a+n+1);
	sort(b+1,b+sum);
	sort(s+1,s+sum2);
	if(ji==0){
		cout<<"0";	
		return 0;
	}
	if(ou==0){
		cout<<a[n-m+1];
		return 0;
	}
//	for(int i=1;i<=sum;i++){
//		cout<<b[i]<<endl; 
//	}
//	cout<<endl;
//	cout<<sum<<" "<<m<<endl; 
		long long l=1;
		long long r=sum2;
		long long ans=0;
		if(sum-1>=m){
			while(l<r){
				long long mid=(l+r)/2;
				//cout<<mid<<" "<<s[mid]<<" "<<b[sum-m+1]<<endl;
				if(s[mid]<=b[sum-m+1]){
					r=mid-1;
					ans=s[mid];
				}
				else{
					l=mid+1;
				}
			}
			cout<<max(b[sum-m],ans);
			return 0;
		}
		else{
			dp[0]=1073741823;
		    for(long long i=1;i<=n;i++){
		    	for(long long j=m;j>=1;j--){
		    		dp[j]=max(dp[j],(dp[j-1]&a[i]));
		    	//	cout<<j<<" "<<dp[j]<<" "<<i<<endl;
				}
			}
			cout<<dp[m];
		}
	return 0;
}
