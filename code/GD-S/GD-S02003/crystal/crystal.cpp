#include<bits/stdc++.h>
#define int long long

using namespace std;

int n,m;
const int N=6e5+55;
int a[N],ans=1,mx=-1;

signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int j=n-1,i=n;
	while(j>=1&&i>=1){
		m=m-(a[i]-a[j]);
		
		while(m<0){
			m=m+(i-j)*(a[i]-a[i-1]);
			i--;
			ans--;
		}
		
		ans++;
		mx=max(mx,ans);
		j--;
	}
	cout<<mx;
	return 0;
}
