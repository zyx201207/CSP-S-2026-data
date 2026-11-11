#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500010];
//int s[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//s[i]=s[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	//for(int i=1;i<=n;i++)cout<<i<<" "<<a[i]<<endl;
	int ans=1;
	int sum=0;
	a[0]=a[1];
	for(int i=1,j=1;i<=n;i++){
		sum+=(a[i]-a[i-1])*(i-j);
		while(j<=i && sum>m){
			sum-=a[i]-a[j];
			j++;
		}
		//cout<<i<<" "<<sum<<" "<<i-j+1<<endl;
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
