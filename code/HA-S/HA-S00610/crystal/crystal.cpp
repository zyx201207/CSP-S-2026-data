#include<bits/stdc++.h>
using namespace std;
long long m,n;
long long a[500005];
long long b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long sum;
	int ans=0;
	for(int i=1;i<=n;i++){
		sum=m;
		for(int j=1;j<=n;j++){
			b[j]=abs(a[i]-a[j]);
		}
		sort(b+1,b+n+1);
		int k=1;
		int cnt=0;
		while(sum>=b[k]&&k<=n){
			sum-=b[k];
			k++;
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
} 

