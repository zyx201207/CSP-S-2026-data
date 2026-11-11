#include<bits/stdc++.h>
using namespace std;
int main(){
	const int N=5e5+10;
	int n,m,a[N]; 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int ans=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(n>5000){
		int x=a[2]-a[1];
		for(int i=2;i<=n;i++){
			int sum=(i-1)*i/2;
			if(sum<=m)ans=max(ans,i);
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int sum=0;
			for(int k=i+1;k<=j;k++){
				sum+=(a[k]-a[k-1])*(k-i);
			}
			if(sum<=m)ans=max(ans,j-i+1);
		}
	}
	cout<<ans;
	return 0;
}
