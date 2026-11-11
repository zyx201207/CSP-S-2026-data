#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	
	for(int i=1;i<=n;i++){
		int sum=0,cnt=0;
		for(int j=i-1;j>=1;j--){
			if(sum+(a[i]-a[j])<=m){
				sum+=(a[i]-a[j]);
				cnt++;
			}
			else{
				ans=max(ans,cnt+2);
				break;
			}
		} 
	}
	cout<<ans;
	return 0;
}

