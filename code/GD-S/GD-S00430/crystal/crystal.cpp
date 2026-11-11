#include<bits/stdc++.h>
using namespace std;
long long ans,n,m,a[500005];
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		long long sum=0,cnt=1;
		for(int j=i-1;j>=1;j--){
			sum+=a[i]-a[j];
			if(sum>m){
				break;
			}
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
} 
