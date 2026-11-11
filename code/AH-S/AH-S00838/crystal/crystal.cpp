#include<bits/stdc++.h>
using namespace std;
#define int long long


int n;
int m;
int a[500099];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int p=0;
	int ans=0;
	int k=0;
	for(int i=1;i<=n;i++){
		if(m-p>=(i-k)*(a[i+1]-a[i])){
			p+=(i-k)*(a[i+1]-a[i]);
			ans++;
		}else{
			k++;
			continue;
		}		
	}
	cout<<ans;
	return 0;
}

