#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
long long a[n+1]={};
	for(long long i=1;i<=n;i++){
		cin>>a[i]; 
	}
	sort(a+1,a+n+1);
	long long c=0;
	long long cnt=1;
	long long ans=1;
	for(long long i=2;i<=n;i++){
		//cout<<endl<<i<<" ";
		for(long long j=i-1;j>=1;j--){
			
			c+=(a[i]-a[j]);
			if(c<=m){
				cnt++;
			}
			else{
				break;
			}
			//cout<<j<<" ";

		}
		ans=max(ans,cnt);
		cnt=1;
		c=0;
	}
	cout<<ans;
	return 0;
} 
