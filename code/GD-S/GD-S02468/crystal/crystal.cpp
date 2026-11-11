#include<bits/stdc++.h>
using namespace std;
long long n,m;
const long long N=5e5+5;
long long a[N],cnt,sum,ans;
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long l=1,r=1;
	while(l<=r){
		if(l>=n||r>=n) break;
		if(l==r){
			r++;
			sum=a[r]-a[l];
		}else{
			if(sum>m){
				sum-=(a[r]-a[l]);
				l++;
			}else if(sum<m){
				r++;
				sum+=(a[r]-a[r-1])*(r-l);
			}else{
				ans=max(ans,r-l+1);
				r++;
				sum+=(a[r]-a[r-1])*(r-l);
				
			}
		}
	} 
	cout<<ans;
	return 0;
}

