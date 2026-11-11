#include<bits/stdc++.h>
using namespace std;
int n,m,arr[500005],x,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",arr+i);
	}
	sort(arr+1,arr+n+1);
	int xj=1;
	for(int i=2;i<=n;i++){
		x+=(i-xj)*(arr[i]-arr[i-1]);
		while(x>m){
			x-=arr[i]-arr[xj];
			xj++;
		}
		ans=max(ans,i-xj+1);
	}
	cout<<ans;
	return 0;
}
