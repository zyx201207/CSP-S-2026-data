#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	int a[n+1];a[0]=0;
	bool bol=1;
	int total=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		total+=(a[i]-a[i-1])*(i-1);
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]){
			bol=0;
		}
	}
	
	
	if(bol){
		int d=a[n]-a[n-1];
		int sum[n+1];
		sum[0]=0;
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+d*(i-1);
			if(sum[i]>m){
				cout<<i-1;
				return 0;
			}
		}
	}
	
	int start=1,end=n,x,y;
	int ans;
	while(1){
		ans=end-start+1;
		if(total<=m){
			cout<<ans;
			break;
		}
		x=(end-start)*(a[end]-a[end-1]);
		y=a[end]-a[start];
		if(total-x<=m||total-y<=m){
			cout<<--ans;
			break;
		}
		else if(x>y){
			start++;
			total-=y;
		}
		else{
			end--;
			total-=x;
		}
	}
	return 0;
}
