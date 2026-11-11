#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	int m;
	int ans;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n;i++){
		int sum=0;
		for(int j=i-1;j>=1;j--){
			sum+=a[i]-a[j];
			if(sum>m) break;
			ans=max(ans,i-j+1);
		}
	}
	cout<<ans;
	return 0;
}
