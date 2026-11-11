#include<bits/stdc++.h>
using namespace std;
long long a[500100];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	sort(a+1,a+n+1);
	long long l=1,r=2;
	long long sum=0,ans=0;
	while(l<=r&&l<=n&&r<=n){
		long long len=r-l;
		if(sum>m){
			sum=sum-(a[r]-a[l]);
			l++;
			continue;
		}
		if(sum<=m){
			sum+=len*(a[r]-a[r-1]);
			ans=max(ans,len);
			r++;
		}
		else{
			sum=sum-(a[r]-a[l]);
			l++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
