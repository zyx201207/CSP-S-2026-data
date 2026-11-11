#include<bits/stdc++.h>
using namespace std;
int n,m;
int maxn;
long long a[100010];
long long sum[100010];
long long ans[100010];
int main(){
	freopen("crystal","r",stdin);
	freopen("crystal","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){ 
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=a[i+1]-a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans[i]=0;
			if(sum[i]<=sum[i+1]){
				ans[i]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(ans[i]<=maxn){
			maxn=2*ans[i];
		}
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
