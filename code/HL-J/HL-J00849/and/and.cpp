#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int ans,mx;
int a[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(m==1){
		cout<<mx;
		return 0;
	}
	if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				int cur=i and j;
				cout<<cur<<endl;
				ans=max(ans,cur);
			}
		}
	}
	//4 2 3 15 12 12
	cout<<ans;
	return 0;
}