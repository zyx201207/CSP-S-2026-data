#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long ans=0;
	
	if(n>5010){
		long long diff=a[2]-a[1];
		long long sum=0;
		long long cnt=1;
		for(int i=1;i<=n;i++){
			sum+=i*diff;
			if(sum<=m) cnt++;
			else break;
		}
		cout<<min(n,cnt);
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		long long cnt=0;
		long long sum=0;
		for(int j=i;j>=1;j--){
			sum+=(a[i]-a[i-j+1]);
			if(sum<=m) cnt++;
			else break;
		}
		ans=max(ans,cnt);
	}
	cout<<min(n,ans);
	return 0;
} 
