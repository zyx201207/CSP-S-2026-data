#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,cnt=0,dp=0,t=0,q;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int s=a[n]; 
	sort(a+1,a+1+n,greater<int>());
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+m-1]&&i+m-1<=n){
			t=a[i];
		}
		t=max(s,t);
	}
	cout<<t;
	return 0;
}

