#include <bits/stdc++.h>
using namespace std;
long long arr[51234560];
long long b[51234560];
long long cost[51234560];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n=0,m=0,sum=0;
	long long ans=0;
	long long s=0;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> arr[i];
		sum+=arr[i];
	}
	sort(arr+1,arr+n+1);

	
	for(int i=1;i<=n;i++){
		int tmpans=0;
		int tmp=m;
		for(int j=i;j>0;j--){
			if(tmp-(arr[i]-arr[j])<0) break;
			tmp-=arr[i]-arr[j];
			tmpans++;
//			cout << tmpans << " ";
		}
		
		if(tmpans>ans) ans=tmpans;
	}	
	
	cout << ans;
	return 0;
}
