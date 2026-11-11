#include<bits/stdc++.h>
using namespace std;
constexpr int N=5e5+5;
int n,ans;
long long m,a[N],cost; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1,j=1;i<=n;i++){
		while(cost>m)cost-=a[i]-a[j++];
		ans=max(ans,i-j+1);
		cost+=(a[i+1]-a[i])*(i-j+1);
	}
	cout<<ans;
	return 0;
}
