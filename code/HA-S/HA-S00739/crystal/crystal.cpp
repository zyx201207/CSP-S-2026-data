#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int k = 2,ans = 0,sum=0;
	for(;k<=n;k++){
		for(int i=k-1;i<k;i++){
			sum+=a[k];
			sum-=a[i];
		}
		if(sum<=m){
			ans=k;
			continue;
		}
	}
	cout<<ans;
	return 0;
}
