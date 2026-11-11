#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	int l=1;
	long long sum=0;
	int ans=1;
	for(int r=2;r<=n;r++){
		sum+=1ll*(r-l)*(a[r]-a[r-1]);
		while(sum>m){
			sum-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans<<endl;
	return 0;
}
