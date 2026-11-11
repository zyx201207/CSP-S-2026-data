#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    long long n,m,ans=0;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		long long sum=0;
		for(long long j=1;j<=i;j++){
			sum+=a[i]-a[j];
		}
		if(sum>m){
		    break;	
		}
		else{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

