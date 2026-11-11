#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],c[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	sort(a+1,a+n+1); 
	for(int i=1;i<=n;i++) c[i]=a[i]-a[i-1];
	long long l=0,r=1,cnt=0,ans=1;
	while(r<n){
		long long p=c[r]*(r-l);
		if(cnt<=(m-p)){
			cnt+=p;
			r++; 
			ans=max(ans,r-l);
		}else{
			l++;
			cnt-=(a[r]-a[l]);
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

