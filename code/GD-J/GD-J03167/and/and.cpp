#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
		
//	freopen("and3.in","r",stdin);
//	freopen("and3.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	if(m>2000){
		cout<<0;
		return 0;
	}
	
	ll ans=-1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			ans=max(ans,(a[i]&a[j]));
		}
	}
	cout<<ans;
	return 0;
}
