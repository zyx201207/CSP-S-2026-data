#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,sum=0,i,m,l=1,ans=0;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(i=2;i<=n;i++){
		sum+=(i-l)*(a[i]-a[i-1]);
		while(sum>m){
			sum-=a[i]-a[l];
			l++;
		}
		ans=max(i-l+1,ans);
	}
	cout<<ans<<endl;
	return 0;
}
/*

*/
