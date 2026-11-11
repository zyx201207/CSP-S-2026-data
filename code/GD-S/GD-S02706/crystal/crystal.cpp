#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long mid=a[n/2+n%2];
	for(int i=n;i>=1;i--){
		if(a[i]>mid) continue;
		if(m<mid-a[i]) break;
		m-=mid-a[i];
		ans++;
	}
	cout<<ans;
} 
