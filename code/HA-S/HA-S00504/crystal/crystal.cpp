#include <bits/stdc++.h>
using namespace std;
int a[100000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int l=1,r=n;
	int sum=0,ans=0;
	while(l<r){
		int mid=(l+r)/2;
		for(int i=l;i<=mid;i++){
			sum+=a[mid]-a[i];
			if(sum<=m) ans++;
			else break;
		}
		if(sum>m) r--;
		
	}
	cout<<ans;
	return 0;
} 
